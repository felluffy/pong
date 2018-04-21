#include "Scores.h"
#include <string>

Score::Score(const std::string &S, unsigned height, unsigned width) : filename(S)
{
	std::cout << __func__ << std::endl;
	scores.resize(SIZE, 0U);
	if (!font.loadFromFile("red-october/Red-October-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
	}
	float offset = ((float)height - 40.f) / 10.f;
	bool left = true;

	for (int i = 0; i != SIZE; ++i)
	{
		Top10[i].setFont(font);
		Top10[i].setFillColor(sf::Color::White);
		if (left)
			Top10[i].setPosition(width / 2.f - offset * 2, 20.f + offset*i), left = false;
		else 
			Top10[i].setPosition(width / 2.f + offset * 2, 20.f + offset*i), left = true;
		Top10[i].setString(std::to_string(0));
	}
	Top10[SIZE].setFont(font);
	Top10[SIZE].setFillColor(sf::Color(255, 244, 233));
	Top10[SIZE].setPosition(width / 1.45f, 20.f + offset*(SIZE - 1));
	Top10[SIZE].setString(std::string("High Scores \nNormal and Hard"));
}

bool Score::checkValidity()
{
	std::cout << __func__ << std::endl;
	ListScores.open(filename, std::ios::app | std::ios::binary | std::ios::in | std::ios::out);
	if (!ListScores.is_open())
		return false;
	ListScores.close();
	return true;
}

void Score::read()
{
	std::cout << __func__ << std::endl;
	ListScores.open(filename, std::ios::binary | std::ios::in | std::ios::out);
	std::vector<unsigned> ivec;

	//if (!ListScores.is_open())
	//	return false;
	scores.clear();
	
	unsigned int score;
	while (ListScores >> score)
	{
		ivec.push_back(score);
		scores.push_back(score);
	}

	//scores.resize(SIZE);
	ListScores.close();
}

void Score::update(unsigned int ascore)
{
	std::cout << __func__ << std::endl;
	scores.push_back(ascore);
	std::sort(scores.begin(), scores.end(), [](int a, int b) { return b < a;});
	scores.resize(SIZE);
	for (int i = 0; i != SIZE; ++i)
	{
		Top10[i].setString(std::to_string(scores[i]));
	}
}

void Score::reset()
{
	std::cout << __func__ << std::endl;
	ListScores.open(filename, std::ios::binary | std::ios::out | std::ios::trunc);
	scores.resize(SIZE, 0U);
	for (auto &it : scores)
	{
		ListScores << it << " ";
	}
	ListScores.close();
}

void Score::write()
{
	std::cout << __func__ << std::endl;
	ListScores.open(filename, std::ios::binary | std::ios::out | std::ios::trunc);
	for (auto &it : scores)
	{
		ListScores << it << " ";
	}
	ListScores.close();
}

void Score::draw(sf::RenderWindow &win)
{
	for (int i = 0; i != SIZE + 1; ++i)
	{
		win.draw(Top10[i]);
	}
}