#include "WinManager.h"
#include <iostream>

sf::WindowManager::WindowManager() :
	windows_(),
	activeWindow(-1)
{
}

sf::WindowManager::WindowManager(std::vector<AbstWnd*> windows) : 
	windows_(windows),
	activeWindow(-1)
{
}

sf::WindowManager::~WindowManager()
{
}

void sf::WindowManager::Run(sf::RenderWindow * wnd)
{
	StandardCursor Cursor(sf::StandardCursor::TYPE::NORMAL);
	Cursor.Set(wnd->getSystemHandle());
	if (Mouse::isButtonPressed(Mouse::Button::Left) && activeWindow != -1)
	{
		windows_[activeWindow]->Deactivate();
		activeWindow = -1;
	}
	for (unsigned int i = 0; i < windows_.size(); i++)
	{
		windows_[i]->Draw(wnd);
		if (windows_[i]->IsHovered(wnd->mapPixelToCoords(Mouse::getPosition(*wnd))))
		{
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				windows_[i]->OnClick();
				if (activeWindow >= 0) windows_[activeWindow]->Deactivate();
				windows_[i]->Activate();
				activeWindow = i;
			}
			StandardCursor Cursor(windows_[i]->GetCursorType());
			Cursor.Set(wnd->getSystemHandle());
		}
	}
}
