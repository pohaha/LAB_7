#pragma once
#include <SFML/System.hpp>
#include <string>
class originPoint
{
public:
	sf::Vector2f position = { 0.f,0.f };
	void move(sf::Vector2f& step);
	std::string show();
	void setOrigin(sf::Vector2f& newPos);

	originPoint(sf::Vector2f pos);
};

