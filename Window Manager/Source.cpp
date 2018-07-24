#include <SFML\Graphics.hpp>
#include <iostream>
#include "WinManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "WinManager");
		
	std::vector<sf::AbstWnd*> windows;

	sf::Color fillColor = sf::Color::Black;

	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text text("On", font, 20);
	text.setFillColor(sf::Color::Black);

	auto lambda1 = [&fillColor]() { fillColor = sf::Color::White; };
	auto lambda2 = [&fillColor]() { fillColor = sf::Color::Black; };

	sf::PtrEngine engine;
	sf::String sampleText = " ";

	sf::Button<decltype(lambda1)> button1(300.0f, 768.0f / 2.0f - 25.0f, 150.0f, 50.0f, sf::Color::Color(181, 181, 181, 255), text, lambda1);
	text.setString("Off");
	sf::Button<decltype(lambda2)> button2(1366.0f - 450.0f, 768.0f / 2.0f - 25.0f, 150.0f, 50.0f, sf::Color::Color(181, 181, 181, 255), text, lambda2);
	text.setString("");
	sf::TextWnd textWnd(1366.0f / 2.0f - 75, 768.0f / 4.0f * 3.0f, 150.0f, 50.0f, sf::Color::Color(181, 181, 181, 255), &sampleText, text, &engine);

	windows.push_back(&button1);
	windows.push_back(&button2);
	windows.push_back(&textWnd);

	sf::WindowManager winManager(windows);
	sf::Text onWindow("", font);
	onWindow.setOrigin(sf::Vector2f(onWindow.getLocalBounds().width / 2, onWindow.getLocalBounds().height / 2));
	onWindow.setPosition(sf::Vector2f(1366.0f / 2.0f, 500.0f));

	sf::String string;

	while (window.isOpen())
	{
		window.clear(fillColor);
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				engine.updateBuffer(event.text.unicode);
				std::cout << static_cast<char>(event.text.unicode);
				break;
			}
		}

		winManager.Run(&window);
		window.display();
	}
}