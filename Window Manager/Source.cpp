//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//#include "D:/TX/TXLib.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "WinManager.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paint");
	window.setFramerateLimit(500);

	sf::String str1 = "111";
	sf::String str2 = "222";

	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text text;
	text.setFillColor(sf::Color::Black);
	text.setFont(font);

	sf::TextWnd text1(100, 100, 150, 50, sf::Color::Cyan, &str1, text);
	sf::TextWnd text2(300, 100, 150, 50, sf::Color::Cyan, &str2, text);

	sf::PencilInst pencil;
	sf::PaintInst paint;

	sf::Canvas canvas1(sf::Vector2f(760, 730), sf::Vector2f(100, 250), sf::Color::Black, 30, &window);
	sf::Canvas canvas2(sf::Vector2f(760, 730), sf::Vector2f(100 + 860, 250), sf::Color::Black, 30, &window);
	
	canvas1.Clear(sf::Color::White);
	canvas2.Clear(sf::Color::White);

	canvas1.SetActiveInst(&pencil);
	canvas2.SetActiveInst(&paint);

	std::vector<sf::AbstWnd*> windows;
	windows.push_back(&text1);
	windows.push_back(&text2);
	windows.push_back(&canvas1);
	windows.push_back(&canvas2);

	window.setKeyRepeatEnabled(true);

	sf::WindowManager manager(windows);
	
	
	while (window.isOpen())
	{
		window.clear(sf::Color::Color(128, 128, 128, 255));
	
		manager.Run(&window);

		if (canvas1.IsHovered(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) canvas1.OnClick();
		if (canvas2.IsHovered(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) canvas2.OnClick();

		window.display();
	}
}