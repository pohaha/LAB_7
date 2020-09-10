#include "originPoint.h"
#include <string>
void originPoint::move(sf::Vector2f& step)
{
	originPoint::position += step;
}
std::string originPoint::show()
{
	std::string mess;
	return mess = "x=" +std::to_string(originPoint::position.x) + "\t y=" + std::to_string(originPoint::position.y);
}
void originPoint::setOrigin(sf::Vector2f& newPos)
{
	originPoint::position = newPos;
}
originPoint::originPoint(sf::Vector2f pos)
{
	originPoint::position = pos;
}