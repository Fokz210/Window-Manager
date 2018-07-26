#include "WinManager.h"

sf::PencilInst::PencilInst() :
	AbstInst()
{

}

void sf::PencilInst::Apply(Vector2f coords, float thickness, Color color, RenderTarget * texture)
{
	RectangleShape rect;
	rect.setSize(Vector2f(thickness * 2, thickness * 2));
	rect.setOrigin(thickness, thickness);
	rect.setPosition(coords);
	rect.setFillColor(color);
	rect.setOutlineThickness(0.0);

	texture->draw(rect);
}

void sf::PencilInst::Preview(sf::Vector2f coords, float thickness, sf::Color color, sf::RenderTarget * texture)
{
	RectangleShape rect;
	rect.setSize(Vector2f(thickness * 2, thickness * 2));
	rect.setOrigin(thickness, thickness);
	rect.setPosition(coords);
	rect.setOutlineColor(color);
	rect.setFillColor(Color::Transparent);
	rect.setOutlineThickness(1.0f);

	texture->draw(rect);
}
