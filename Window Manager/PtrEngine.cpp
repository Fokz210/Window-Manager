#include "WinManager.h"
#include <iostream>

sf::PtrEngine::PtrEngine()
{
}

sf::PtrEngine::~PtrEngine()
{
}

char sf::PtrEngine::getBufferedString()
{
	return buffer_;
}

bool sf::PtrEngine::isBufferEmpty()
{
	return !buffer_;
}

void sf::PtrEngine::eraseBuffer()
{
	buffer_ = NULL;
}

void sf::PtrEngine::updateBuffer(Uint32 character)
{
	buffer_ = static_cast<char>(character);
}
