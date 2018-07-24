#include "WinManager.h"
#include <iostream>

sfext::PtrEngine::PtrEngine()
{
}

sfext::PtrEngine::~PtrEngine()
{
}

char sfext::PtrEngine::getBufferedString()
{
	return buffer_;
}

bool sfext::PtrEngine::isBufferEmpty()
{
	return !buffer_;
}

void sfext::PtrEngine::eraseBuffer()
{
	buffer_ = NULL;
}

void sfext::PtrEngine::updateBuffer(Uint32 character)
{
	buffer_ = static_cast<char>(character);
}
