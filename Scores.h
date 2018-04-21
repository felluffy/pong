#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#define SIZE 10U

class Score
{
public:
	Score(const std::string&, unsigned, unsigned);
//	~Score();
	void update(unsigned int);
	void reset();
	void read();
	bool checkValidity();
	void write();
	void draw(sf::RenderWindow &win);
private:
	std::vector<unsigned int> scores;
	std::fstream ListScores;
	const std::string filename;

	sf::Font font;
	sf::Text Top10[SIZE+1];
};