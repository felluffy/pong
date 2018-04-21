
#include "diffSelection.hpp"
#include <iostream>

diffSelection::diffSelection(float width, float height): currentDiff(std::string("Current Difficulty: Normal"))
{
	if (!font.loadFromFile("red-october/Red-October-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		//	exit(EXIT_FAILURE);
	}

	difficulties[0].setFont(font);
	difficulties[0].setFillColor(sf::Color::Red);
	difficulties[0].setStyle(sf::Text::Bold);
	difficulties[0].setString("Normal");
	difficulties[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_DIFFS + 1) * 1));

	difficulties[1].setFont(font);
	//menu[1].setColor(sf::Color::White);
	difficulties[1].setString("Hard");
	difficulties[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_DIFFS + 1) * 2));

	difficulties[2].setFont(font);
	difficulties[2].setFillColor(sf::Color::Green);
	difficulties[2].setStyle(sf::Text::Bold);
	difficulties[2].setString(currentDiff);
	difficulties[2].setPosition(20.f, 20.f);
	difficulties[2].setCharacterSize(15);


	selectedItemIndex = 0;
}


diffSelection::~diffSelection()
{
}

void diffSelection::draw(sf::RenderWindow &window)
{
	//	window.clear();
	difficulties[2].setString(currentDiff);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_DIFFS; i++)
	{
		window.draw(difficulties[i]);
	}
	//	window.display();
}

void diffSelection::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		difficulties[selectedItemIndex].setStyle(sf::Text::Regular);
		difficulties[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		difficulties[selectedItemIndex].setStyle(sf::Text::Bold);
		difficulties[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void diffSelection::MoveDown()
{
	if (selectedItemIndex < MAX_NUMBER_OF_ITEMS_DIFFS - 2)
	{
		difficulties[selectedItemIndex].setStyle(sf::Text::Regular);
		difficulties[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		difficulties[selectedItemIndex].setStyle(sf::Text::Bold);
		difficulties[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}


int diffSelection::GetPressedItem()
{
	if (selectedItemIndex == 0)
		currentDiff = std::string("Current Difficulty: Normal");
	else
		currentDiff = std::string("Current Difficulty: Hard");
	return selectedItemIndex;
}