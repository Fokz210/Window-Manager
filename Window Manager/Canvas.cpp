#include "WinManager.h"

sfext::Canvas::Canvas(Vector2f size, Vector2f pos, RenderWindow * window, Texture * background = nullptr) :
	texture_(),
	curr_instrument_(nullptr),
	shape_(),
	window_(window)
{
	texture_.create(size.x, size.y);
	if (background != nullptr)
		texture_.draw(Sprite(*background));
	
	shape_.setTexture(texture_.getTexture());
	shape_.setPosition(pos);
}

void sfext::Canvas::LoadTexture(Texture texture)
{
	texture_.draw(Sprite(texture));
}

sf::Texture sfext::Canvas::GetTexture()
{
	return texture_.getTexture();
}

void sfext::Canvas::SetActiveInst(AbstInst * inst)
{
	curr_instrument_ = inst;
}

void sfext::Canvas::OnClick()
{
	curr_instrument_->apply(Vector2f(texture_.mapPixelToCoords(Mouse::getPosition(*window_)).x - shape_.getPosition().x, Mouse::getPosition(*window_).y - shape_.getPosition().y) );
}

void sfext::Canvas::Draw()
{
	shape_.setTexture(texture_.getTexture);
	window_->draw(shape_);
}
