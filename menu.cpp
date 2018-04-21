
#include "Menu.hpp"
#include <iostream>

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("red-october/Red-October-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
	//	exit(EXIT_FAILURE);
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	menu[1].setFont(font);
	//menu[1].setColor(sf::Color::White);
	menu[1].setString("Difficulty");	
	menu[1].setPosition(sf::Vector2f(width / 2 - 50.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[4].setFont(font);
	//menu[2].setColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	menu[3].setFont(font);
	menu[3].setString("Enable or Disable fullscreen");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[2].setFont(font);
	menu[2].setString("High Scores");
	menu[2].setPosition(sf::Vector2f(width / 2 - 70.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));


	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
//	window.clear();
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
//	window.display();
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setStyle(sf::Text::Regular);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setStyle(sf::Text::Bold);
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setStyle(sf::Text::Regular);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setStyle(sf::Text::Bold);
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

