#pragma once

#include "common.h"


class Point
{
public:
	//method to get the current location of an object
	std::string show();
	//methods of manipulating the position of a current object
	virtual void move( const sf::Vector2f& step);
	void setPos(sf::Vector2f& newPos);

	//parametr c-tor
	Point(sf::Vector2f pos);
	
	//default c-tor
	Point();

	sf::Vector2f position = { 0.f,0.f };
protected:
};

