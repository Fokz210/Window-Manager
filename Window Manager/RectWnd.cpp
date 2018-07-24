#include "WinManager.h"



sfext::RectWnd::RectWnd()
{
}

sfext::RectWnd::RectWnd(sf::RectangleShape shape) :
	shape_(shape)
{
}

sfext::RectWnd::RectWnd(float x, float y, float width, float height, Color color) :
	shape_()
{
	shape_.setPosition(Vector2f(x, y));
	shape_.setSize(Vector2f(width, height));
	shape_.setFillColor(color);
}

sfext::RectWnd::~RectWnd()
{
}

void sfext::RectWnd::Activate()
{
	isActive = true;
}

void sfext::RectWnd::Deactivate()
{
	isActive = false;
}

void sfext::RectWnd::OnClick()
{
}

void sfext::RectWnd::Draw(sf::RenderWindow * wnd)
{
	wnd->draw(shape_);
}

bool sfext::RectWnd::IsHovered(sf::Vector2f pos)
{
	return pos.x >= shape_.getPosition().x && pos.x <= shape_.getPosition().x + shape_.getSize().x && pos.y >= shape_.getPosition().y && pos.y <= shape_.getPosition().y + shape_.getSize().y;
}

sfext::StandardCursor::TYPE sfext::RectWnd::GetCursorType()
{
	return StandardCursor::TYPE::HAND;
}
