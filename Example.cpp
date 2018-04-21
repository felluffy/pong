/*

#include "diffSelection.hpp"
#include <SFML\Graphics.hpp>
#include "menu.hpp"
#include <iostream>

int main()
{
	bool inMenu = true;
	bool inDiff = false;
	Menu menu(1280, 720);
	diffSelection difficulties(1280, 720);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "barf");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:		window.close();
										break;
			case sf::Event::KeyReleased:
			{

				if(inMenu)
				switch (event.key.code)
				{
				case sf::Keyboard::Up:	menu.MoveUp();
					break;
				case sf::Keyboard::Down: menu.MoveDown();
					break;
				case sf::Keyboard::Return:  switch (menu.GetPressedItem())
											{
											case 0:				inMenu = false;
																std::cout << "Play pressed" << std::endl;
																break;
											case 1:				std::cout << "options pressed" << std::endl;
																inDiff = true;
																inMenu = false;
																break;
											case 2:				std::cout << "Exit pressed" << std::endl;
																window.close();
																break;
											}
											break;
				default:
					break;
				}
				if (inDiff)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up: 
						difficulties.MoveUp();
						break;
					case sf::Keyboard::Down: 
						difficulties.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (difficulties.GetPressedItem())
						{
						default: 
							break;
						}
					}
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					inMenu = true;
					inDiff = false;
				}
			}

			}
		}
		window.clear();
		if (inDiff)
			difficulties.draw(window);
		else
			menu.draw(window);
		window.display();
	}
}

*/