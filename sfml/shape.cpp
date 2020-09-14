#include "shape.h"
#include "common.h"

//c-tors, d-tors implementation:
	//parametr c-tors
shape::shape(unsigned int&& n_width, unsigned int&& n_height, allocType alloc = STATIC) :
	shape::m_Width(n_width),shape::m_Height(n_height),shape::m_alloc(alloc)
{}
shape::shape(sf::Vector2u n_Dimensions, allocType alloc = STATIC) : 
	m_Width(n_Dimensions.x), m_Height(n_Dimensions.y),m_alloc(alloc)
{}

	//copy c-tor
shape::shape(const shape& n_shape)
{
	shape::LocalOrigin = n_shape.LocalOrigin;
	shape::m_Shape = n_shape.m_Shape;
	shape::m_points = n_shape.m_points;
}

	//d-tor
shape::~shape()
{

}

//manip methods implementation
	//resize method implementation
void shape::setSize(int n_height, int n_width)
{
	m_Height = n_height;
	m_Width = n_width;
}

	//set origin implementation
void shape::setLocalOrigin(sf::Vector2f n_Origin)
{ 
	LocalOrigin = n_Origin;
}

//--TEST--
	//setborder method implementation
void shape::setborder()
{
	shape::m_Shape.setPointCount(4);
	shape::m_Shape.setPoint(0, position);
	shape::m_Shape.setPoint(1, position + sf::Vector2f(m_Width, 0));
	shape::m_Shape.setPoint(2, position + sf::Vector2f(m_Width, m_Height));
	shape::m_Shape.setPoint(3, position + sf::Vector2f(0, m_Height));
	shape::m_Shape.setOutlineColor(sf::Color::White);
	shape::m_Shape.setFillColor(sf::Color::Transparent);
	shape::m_Shape.setOutlineThickness(1);
}
	//draw method implementation
void shape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape::m_Shape);
	sf::CircleShape originPoint(3);
	originPoint.setFillColor(sf::Color::Green);
	originPoint.setPosition(position+LocalOrigin);
	target.draw(originPoint);
}

	

