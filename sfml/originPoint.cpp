#include "originPoint.h"
#include <string>
void Point::move(sf::Vector2f& step)
{
	Point::position += step;
}
std::string Point::show()
{
	std::string mess;
	return mess = "x=" +std::to_string(Point::position.x) + "\t y=" + std::to_string(Point::position.y);
}
void Point::setPos(sf::Vector2f& newPos)
{
	Point::position = newPos;
}
Point::Point(sf::Vector2f pos)
{
	Point::position = pos;
}
Point::Point()
{

}