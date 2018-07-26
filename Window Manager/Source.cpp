#include "D:/TX/TXLib.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "WinManager.h"

using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Paint");
	
	PaintInst paint;
	PencilInst pencil;
	Canvas canvas(Vector2f(1266, 668), Vector2f(50, 50), Color::Black, 30.0, &window);
	canvas.SetActiveInst(&paint);
	canvas.Clear(Color::White);

	float thickness = 5.0;

	while (window.isOpen())
	{
		window.clear(Color::Color(128, 128, 128, 255));
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

		if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
			canvas.SetActiveInst(&paint);
		if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
			canvas.SetActiveInst(&pencil);

		if (Keyboard::isKeyPressed(Keyboard::Key::Q))
			canvas.SetColor(Color::Black);
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
			canvas.SetColor(Color::Red);
		if (Keyboard::isKeyPressed(Keyboard::Key::E))
			canvas.SetColor(Color::Green);
		if (Keyboard::isKeyPressed(Keyboard::Key::R))
			canvas.SetColor(Color::Blue);

		if (Keyboard::isKeyPressed(Keyboard::Key::Z) && thickness > 0)
			thickness -= 0.1f;
		if (Keyboard::isKeyPressed(Keyboard::Key::X))
			thickness += 0.1f; 
		if (Keyboard::isKeyPressed(Keyboard::Key::C))
			canvas.Clear(Color::White);

		canvas.SetThickness(thickness);

		canvas.Draw();
		window.display();
	}
}