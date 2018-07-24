#include "WinManager.h"
#include <iostream>
sfext::TextWnd::TextWnd() :
	RectWnd(),
	text_(),
	engine_(nullptr),
	string_(nullptr),
	wasActive(false),
	cursorPos(0),
	mousePos(),
	timer()
{

}

sfext::TextWnd::TextWnd(RectangleShape shape, Font font, String * string, Text text, PtrEngine * engine) :
	RectWnd(shape),
	text_(text),
	engine_(engine),
	string_(string),
	wasActive(false),
	cursorPos(string_->getSize()),
	mousePos(),
	timer()
{
	text_.setString(*string_);
	text_.setPosition(Vector2f(shape_.getPosition().x + 2.0f, shape_.getPosition().y + 2.0f));
}

sfext::TextWnd::TextWnd(float x, float y, float width, float height, Color color, String * string, Text text, PtrEngine * engine) :
	RectWnd(x, y, width, height, color),
	text_(text),
	engine_(engine),
	string_(string),
	wasActive(false),
	cursorPos(string_->getSize()),
	mousePos(),
	timer()
{
	text_.setString(*string_);
	text_.setPosition(Vector2f(shape_.getPosition().x + 2.0f, shape_.getPosition().y + 2.0f));
}

sfext::TextWnd::~TextWnd()
{
}

void sfext::TextWnd::OnClick()
{
	for (unsigned int i = 0; i < string_->getSize(); i++)
	{
		if (mousePos.x > text_.findCharacterPos(i).x && mousePos.x < text_.findCharacterPos(i).x + text_.getCharacterSize() ) cursorPos = i;
	}
}

void sfext::TextWnd::Draw(RenderWindow * wnd)
{
	
	wnd->draw(shape_);

	if (isActive && wasActive)
	{
		static bool wasKeyPressed = false;
		char buffer = engine_->getBufferedString();
		engine_->eraseBuffer();

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && cursorPos >= 0 && !wasKeyPressed)
		{
			cursorPos--;
			wasKeyPressed = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && (cursorPos <= string_->getSize() || cursorPos <= 0) && !wasKeyPressed)
		{
			cursorPos++;
			wasKeyPressed = true;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::Key::Left) && !Keyboard::isKeyPressed(Keyboard::Key::Right))
			wasKeyPressed = false;
		
		if (buffer == 8 && string_->getSize() > 0)
		{
			string_->erase(cursorPos);
			cursorPos--;
		}
		else if (buffer >= 32)
		{
			string_->insert(cursorPos + 1, buffer);
			cursorPos++;
		}
		text_.setString(*string_);
	}
	else if (isActive && !wasActive)
	{
		engine_->eraseBuffer();
		wasActive = true;
	}
	else if (!isActive)
	{
		wasActive = false;
	}
	
	RectangleShape cursorShape;
	cursorShape.setSize(Vector2f(2.0f, text_.getLocalBounds().height + text_.getLocalBounds().height / 3 ));
	cursorShape.setFillColor(text_.getFillColor());
	cursorShape.setPosition(text_.findCharacterPos(cursorPos + 1));

	text_.setOrigin(Vector2f(0, text_.getLocalBounds().height / 2));
	text_.setPosition(Vector2f(shape_.getPosition().x + 2, shape_.getPosition().y + shape_.getLocalBounds().height / 2));

	wnd->draw(text_);
	if (isActive && int(timer.getElapsedTime().asSeconds() * 2) % 2 == 0) wnd->draw(cursorShape);
	mousePos = wnd->mapPixelToCoords(Mouse::getPosition(*wnd));
}

sfext::StandardCursor::TYPE sfext::TextWnd::GetCursorType()
{
	return StandardCursor::TYPE::TEXT;
}
