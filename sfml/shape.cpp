#include "shape.h"
#include "common.h"

//c-tors, d-tors implementation:
	//default c-tor
shape::shape()
{

}

	//parametr c-tors
shape::shape(unsigned int n_width, unsigned int n_height) :
	m_Width(n_width),m_Height(n_height)
{}
shape::shape(sf::Vector2u n_Dimensions) : 
	m_Width(n_Dimensions.x), m_Height(n_Dimensions.y)
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
	delete(m_points);
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



	

