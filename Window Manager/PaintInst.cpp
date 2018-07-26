#include "WinManager.h"

sf::PaintInst::PaintInst() :
	AbstInst()
{

}

void sf::PaintInst::Apply(Vector2f coords, float thickness, Color color, RenderTexture * texture)
{
	CircleShape circle;
	circle.setRadius(thickness);
	circle.setOrigin(Vector2f(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2));
	circle.setPosition(coords);
	circle.setFillColor(color);
	circle.setOutlineThickness(0.0);
	texture->draw(circle);
}
