#include "WinManager.h"

sfext::Canvas::Canvas(Vector2f size, Texture * background = nullptr) :
	texture_(),
	curr_instrument_(nullptr)
{
	texture_.create(size.x, size.y);
	if (background != nullptr)
		texture_.draw(Sprite(*background));
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
}

void sfext::Canvas::Draw()
{
}
