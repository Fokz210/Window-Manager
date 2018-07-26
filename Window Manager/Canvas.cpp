#include "WinManager.h"

sf::Canvas::Canvas(sf::Vector2f canvSize, sf::Vector2f pos, sf::Color color, float thickness, sf::RenderWindow * window, sf::Texture * background) :
	texture_(),
	curr_instrument_(nullptr),
	shape_(),
	window_(window),
	color_(color),
	thickness_(thickness)
{
	texture_.create(unsigned int (canvSize.x), unsigned int (canvSize.y));
	if (background != nullptr)
		texture_.draw(Sprite(*background));
	
	shape_.setTexture(texture_.getTexture());
	shape_.setPosition(pos);
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

void sf::Canvas::OnClick()
{
	 curr_instrument_->Apply(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_)).x - shape_.getPosition().x, Mouse::getPosition(*window_).y - shape_.getPosition().y), thickness_, color_, &texture_);
}

void sf::Canvas::Draw()
{
	texture_.display();
	shape_.setTexture(texture_.getTexture());
	window_->draw(shape_);
	curr_instrument_->Preview(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_))), thickness_, color_, window_);
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
