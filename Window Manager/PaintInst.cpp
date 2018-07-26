#include "WinManager.h"

sf::PaintInst::PaintInst() :
	AbstInst()
{

}

void sf::PaintInst::Apply(Vector2f coords, float thickness, Color color, RenderTarget * texture)
{
	CircleShape circle;
	circle.setRadius(thickness);
	circle.setOrigin(Vector2f(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2));
	circle.setPosition(coords);
	circle.setFillColor(color);
	circle.setOutlineThickness(0.0);
	texture->draw(circle);
}

void sf::PaintInst::Preview(sf::Vector2f coords, float thickness, sf::Color color, sf::RenderTarget * texture)
{
	CircleShape circle;
	circle.setRadius(thickness);
	circle.setOrigin(Vector2f(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2));
	circle.setPosition(coords);
	circle.setFillColor(Color::Color(0, 0, 0, 0));
	circle.setOutlineColor(color);
	circle.setOutlineThickness(1.0f);
	texture->draw(circle);
}
