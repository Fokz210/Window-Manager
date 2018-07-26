#include "D:/TX/TXLib.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "WinManager.h"

using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "WinManager");
	
	PaintInst inst;
	Canvas canvas(Vector2f(700, 500), Vector2f(50, 50), Color::White, 30.0, &window);
	canvas.SetActiveInst(&inst);

	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		if (Mouse::isButtonPressed(Mouse::Button::Left))
			canvas.OnClick();

		canvas.Draw();
		window.display();
	}
}