#include "WinManager.h"

sf::Canvas::Canvas() :
	texture_(),
	curr_instrument_(nullptr)
{
}

sf::Canvas::Canvas(Vector2f size, Texture * background = nullptr) :
	texture_(),
	curr_instrument_(nullptr)
{
}