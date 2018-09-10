//#pragma comment(linker, "/SUBSYSTEM:windows")
#include "D:/TX/TXLib.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Include/WinManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paint");
	window.setFramerateLimit(500000);

	sf::String str1 = "First";
	sf::String str2 = "Second";

	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text text;
	text.setFillColor(sf::Color::Black);
	text.setFont(font);

	sf::TextWnd text1(100, 100, 810, 50, sf::Color::Cyan, &str1, text);
	sf::TextWnd text2(1010, 100, 810, 50, sf::Color::Cyan, &str2, text);

	sf::PencilInst pencil;
	sf::PaintInst paint;

	std::vector<sf::AbstInst*> palette_vector;
	palette_vector.push_back(&pencil);
	palette_vector.push_back(&paint);

	sf::Palette palette(palette_vector);

	sf::Shader sprayShader;
	sprayShader.loadFromFile("sprayShader.frag", sf::Shader::Fragment);

	sf::Spray spray(&sprayShader);

	sf::Canvas canvas1(sf::Vector2f(810, 730), sf::Vector2f(100, 250), sf::Color::Black, 30, palette, &window);
	sf::Canvas canvas2(sf::Vector2f(810, 730), sf::Vector2f(1010, 250), sf::Color::Black, 30, palette, &window);
	
	canvas1.Clear(sf::Color::White);
	canvas2.Clear(sf::Color::White);

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