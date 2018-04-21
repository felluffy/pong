#pragma once
#include "SFML/Graphics.hpp"

#define MAX 4

class PlayerScreen
{
public:
	PlayerScreen(float width, float height);
	~PlayerScreen();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	//int GetPressedItem() { return selectedItemIndex; }
	int GetPressedItem();

private:
	std::string currentNumPlayer;
	int selectedItemIndex;
	sf::Font font;
	sf::Text numPlayers[MAX];

};
//#pragma once
