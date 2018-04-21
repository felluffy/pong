#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS_DIFFS 3

class diffSelection
{
public:
	diffSelection(float width, float height);
	~diffSelection();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
//	int GetPressedItem() { return selectedItemIndex; }
	int GetPressedItem();

private:
	std::string currentDiff;
	int selectedItemIndex;
	sf::Font font;
	sf::Text difficulties[MAX_NUMBER_OF_ITEMS_DIFFS];

};
#pragma once
