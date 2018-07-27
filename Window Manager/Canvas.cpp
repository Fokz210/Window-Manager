#include "WinManager.h"

sf::Canvas::Canvas(sf::Vector2f canvSize, sf::Vector2f pos, sf::Color color, float thickness, sf::RenderWindow * window, sf::Texture * background) :
	RectWnd(pos.x, pos.y, canvSize.x, canvSize.y, color),
	texture_(),
	curr_instrument_(nullptr),
	shapeSprite_(),
	window_(window),
	color_(color),
	thickness_(thickness)
{
	texture_.create(unsigned int (canvSize.x), unsigned int (canvSize.y));
	if (background != nullptr)
		texture_.draw(Sprite(*background));
	
	shapeSprite_.setTexture(texture_.getTexture());
	shapeSprite_.setPosition(pos);
}

void sf::Canvas::LoadTexture(Texture texture)
{
	texture_.draw(Sprite(texture));
}

sf::Texture sf::Canvas::GetTexture()
{
	return texture_.getTexture();
}

void sf::Canvas::SetActiveInst(AbstInst * inst)
{
	curr_instrument_ = inst;
}

bool sf::Canvas::OnClick(Event::MouseButtonEvent event)
{
	 curr_instrument_->Apply(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_)).x - shape_.getPosition().x, Mouse::getPosition(*window_).y - shape_.getPosition().y), thickness_, color_, &texture_);
	 return true;
}

bool sf::Canvas::OnClick()
{
	curr_instrument_->Apply(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_)).x - shape_.getPosition().x, Mouse::getPosition(*window_).y - shape_.getPosition().y), thickness_, color_, &texture_);
	return true;
}

void sf::Canvas::Draw(RenderWindow * wnd)
{
	texture_.display();
	shapeSprite_.setTexture(texture_.getTexture());
	window_->draw(shapeSprite_);
	if (IsHovered(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_))))) curr_instrument_->Preview(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_))), thickness_, color_, window_);
}


void sf::Canvas::Clear(sf::Color clearColor)
{
	texture_.clear(clearColor);
}

void sf::Canvas::SetThickness(float thickness)
{
	thickness_ = thickness;
}

void sf::Canvas::SetColor(Color color)
{
	color_ = color;
}

bool sf::Canvas::OnKey(Event::KeyEvent event)
{
	switch (event.code)
	{
	case Keyboard::Key::Q:
	{
		SetColor(sf::Color::Black);
		break;
	}

	case Keyboard::Key::W:
	{
		SetColor(sf::Color::Red);
		break;
	}

	case Keyboard::Key::E:
	{
		SetColor(sf::Color::Green);
		break;
	}

	case Keyboard::Key::R:
	{
		SetColor(sf::Color::Blue);
		break;
	}

	case Keyboard::Key::Z:
	{
		if (thickness_ > 0) thickness_ -= 5;
		break;
	}

	case Keyboard::Key::X:
	{
		thickness_ += 5;
		break;
	}

	default:
		break;
	}
	return isActive;
}
