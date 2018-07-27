#include "WinManager.h"



sf::RectWnd::RectWnd()
{
}

sf::RectWnd::RectWnd(sf::RectangleShape shape) :
	shape_(shape)
{
}

sf::RectWnd::RectWnd(float x, float y, float width, float height, sf::Color color) :
	shape_()
{
	shape_.setPosition(Vector2f(x, y));
	shape_.setSize(Vector2f(width, height));
	shape_.setFillColor(color);
}

sf::RectWnd::~RectWnd()
{
}

void sf::RectWnd::Activate()
{
	isActive = true;
}

void sf::RectWnd::Deactivate()
{
	isActive = false;
}

bool sf::RectWnd::OnClick(Event::MouseButtonEvent event)
{
	return false;
}

bool sf::RectWnd::OnTextEntered(Event::TextEvent event)
{
	return false;
}

void sf::RectWnd::Draw(sf::RenderWindow * wnd)
{
	wnd->draw(shape_);
}

bool sf::RectWnd::IsHovered(sf::Vector2f pos)
{
	return pos.x >= shape_.getPosition().x && pos.x <= shape_.getPosition().x + shape_.getSize().x && pos.y >= shape_.getPosition().y && pos.y <= shape_.getPosition().y + shape_.getSize().y;
}

sf::StandardCursor::TYPE sf::RectWnd::GetCursorType()
{
	return StandardCursor::TYPE::HAND;
}

bool sf::RectWnd::OnKey(Event::KeyEvent event)
{
	return false;
}

bool sf::RectWnd::OnMouseMove(Event::MouseMoveEvent event)
{
	return false;
}
