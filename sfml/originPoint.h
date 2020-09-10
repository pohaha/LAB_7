#pragma once
#include "common.h"

class Point
{
public:
	sf::Vector2f position = { 0.f,0.f };
	void move(sf::Vector2f& step);
	std::string show();
	void setOrigin(sf::Vector2f& newPos);

	Point(sf::Vector2f pos);
	Point();
};

