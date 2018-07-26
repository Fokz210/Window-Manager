#pragma once
#include "SFML\Graphics.hpp"
#include "StandardCursor.h"
#include <vector>

class Noncopyable
{
public:
	Noncopyable() {}
	Noncopyable(const Noncopyable & that) = delete;
	Noncopyable & operator = (const Noncopyable & that) = delete;
};

namespace sf
{
	class AbstWnd
	{
	public:
		AbstWnd();
		virtual void Activate() = 0;
		virtual void Deactivate() = 0;
		virtual void OnClick() = 0;
		virtual void Draw(RenderWindow * wnd) = 0;
		virtual bool IsHovered(Vector2f pos) = 0;
		virtual StandardCursor::TYPE GetCursorType() = 0;
	};

	class WindowManager
	{
	public:
		WindowManager();
		WindowManager(std::vector<AbstWnd*> windows);
		~WindowManager();
		void Run(RenderWindow * wnd);
		
	private:
		std::vector<AbstWnd*> windows_;
		int activeWindow;
	};

	class RectWnd :
		public AbstWnd
	{
	public:
		RectWnd();
		RectWnd(RectangleShape shape);
		RectWnd(float x, float y, float width, float height, Color color);
		~RectWnd();
		virtual void Activate() override;
		virtual void Deactivate() override;
		virtual void OnClick() override;
		virtual void Draw(RenderWindow * wnd) override;
		virtual bool IsHovered(Vector2f pos) override;
		virtual StandardCursor::TYPE GetCursorType() override;

	protected:
		sf::RectangleShape shape_;
		bool isActive;
	};

	template <class FN>
	class Button :
		public RectWnd
	{
	public:
		Button(RectangleShape shape, Text text, FN function) :
			AbstWnd(),
			text_(text),
			function_(function)
		{
			FloatRect textRect = text_.getLocalBounds();
			text_.setOrigin(textRect.width / 2, textRect.height / 2);
			text_.setPosition(shape_.getPosition() + shape_.getSize() / 2);
		}

		Button(float x, float y, float width, float height, Color color, Text text, FN function) :
			RectWnd(x, y, width, height, color), 
			text_(text),
			function_(function)
		{
			FloatRect textRect = text_.getLocalBounds();
			text_.setOrigin(textRect.width / 2, textRect.height / 2);
			text_.setPosition(shape_.getPosition() + Vector2f(shape_.getSize().x / 2, shape_.getSize().y / 2));
		}

		~Button()
		{
		}

		virtual void OnClick() override
		{
			function_();
		}

		virtual void Draw(RenderWindow * wnd) override
		{
			wnd->draw(shape_);
			wnd->draw(text_);
		}

	protected:
		Text text_;
		FN function_;
	};

	class PtrEngine
	{
	public:
		PtrEngine();
		~PtrEngine();
		char getBufferedString();
		bool isBufferEmpty();
		void eraseBuffer();
		void updateBuffer(Uint32 character);

	private:
		char buffer_;
	};

	class TextWnd :
		public RectWnd
	{
	public:
		TextWnd();
		TextWnd(RectangleShape shape, Font font, String * string, Text text, PtrEngine * engine);
		TextWnd(float x, float y, float width, float height, Color color, String * string, Text text, PtrEngine * engine);
		~TextWnd();
		virtual void OnClick() override;
		virtual void Draw(RenderWindow * wnd) override;
		virtual StandardCursor::TYPE GetCursorType() override;

	protected:
		sf::Text text_;
		sf::String * string_;
		PtrEngine * engine_;
		bool wasActive;
		int cursorPos;
		sf::Vector2f mousePos;
		sf::Clock timer;
	};

	class AbstInst
	{
	public:
		AbstInst();
		virtual void Apply(Vector2f coords, float thickness, Color color, RenderTexture * texture) = 0;
	};

	class Canvas :
		public Noncopyable
	{
	public:
		Canvas(sf::Vector2f canvSize, sf::Vector2f pos, sf::Color color, float thickneess, sf::RenderWindow * window, sf::Texture * background = nullptr);
		void LoadTexture(sf::Texture texture);
		sf::Texture GetTexture();
		void SetActiveInst(AbstInst * inst);
		void OnClick();
		void Draw();
		void Clear(sf::Color clearColor);

	private:
		sf::RenderWindow * window_;
		sf::RenderTexture texture_;
		sf::Sprite shape_;
		AbstInst * curr_instrument_;
		sf::Color color_;
		float thickness_;
	};

	// In the shader code must be at least 3 used uniforms:
	// vec2 position, float thickness, vec4 color and sampler2D texture.	
	// Without them application will crash!
	class FilterInst :
		public AbstInst
	{
	public:
		FilterInst(sf::Shader * filter);
		virtual void Apply(sf::Vector2f coords, float thickness, sf::Color color, sf::RenderTexture * texture) override;
		void ChangeShader(sf::Shader * filter);

	protected:
		sf::Shader * filter_;
		void applyShader(const sf::Shader * shader, sf::RenderTarget * output);
	};

	class PaintInst :
		public AbstInst
	{
	public:
		PaintInst();
		virtual void Apply(Vector2f coords, float thickness, Color color, RenderTexture * texture) override;
	};
	
}


