#include <iostream>
#include "playerScreen.h"
PlayerScreen::PlayerScreen(float width, float height): currentNumPlayer(std::string("Single Player"))
{
	if (!font.loadFromFile("red-october/Red-October-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		//	exit(EXIT_FAILURE);
	}

	numPlayers[0].setFont(font);
	numPlayers[0].setFillColor(sf::Color::Red);
	numPlayers[0].setStyle(sf::Text::Bold);
	numPlayers[0].setString("Single player, W/S to move");
	numPlayers[0].setPosition(sf::Vector2f(width / 3.f, height / (MAX + 1) * 1));

	numPlayers[1].setFont(font);
	//menu[1].setColor(sf::Color::White);
	numPlayers[1].setString("Multiplayer, W/S and UP/DOWN to move");
	numPlayers[1].setPosition(sf::Vector2f(width / 4.5f, height / (MAX + 1) * 2));

	numPlayers[3].setFont(font);
	numPlayers[3].setFillColor(sf::Color::Green);
	numPlayers[3].setPosition(20.f, 20.f);
	numPlayers[3].setString(currentNumPlayer);
	numPlayers[3].setCharacterSize(15);

	numPlayers[2].setFont(font);
	//menu[1].setColor(sf::Color::White);
	numPlayers[2].setString("Practice against wall");
	numPlayers[2].setPosition(sf::Vector2f(width / 3.f, height / (MAX + 1) * 3));

	selectedItemIndex = 0;
}


PlayerScreen::~PlayerScreen()
{
}

void PlayerScreen::draw(sf::RenderWindow &window)
{
	//	window.clear();
	numPlayers[3].setString(currentNumPlayer);
	for (int i = 0; i < MAX; i++)
	{
		window.draw(numPlayers[i]);
	}
	//	window.display();
}

void PlayerScreen::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		numPlayers[selectedItemIndex].setStyle(sf::Text::Regular);
		numPlayers[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		numPlayers[selectedItemIndex].setStyle(sf::Text::Bold);
		numPlayers[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void PlayerScreen::MoveDown()
{
	if (selectedItemIndex < MAX - 2)
	{
		numPlayers[selectedItemIndex].setStyle(sf::Text::Regular);
		numPlayers[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		numPlayers[selectedItemIndex].setStyle(sf::Text::Bold);
		numPlayers[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}


int PlayerScreen::GetPressedItem()
{
	if (selectedItemIndex == 0)
		currentNumPlayer = std::string("Single player");
	else if (selectedItemIndex == 1)
		currentNumPlayer = std::string("Multiplayer");
	else if (selectedItemIndex == 2)
		currentNumPlayer = std::string("Practice");
	return selectedItemIndex;
}