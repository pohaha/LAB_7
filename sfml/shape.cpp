#include "shape.h"
#include "common.h"

//c-tors, d-tors implementation:
	//parametr c-tors
shape::shape(unsigned int n_width, unsigned int n_height, allocType alloc = STATIC) :
	m_Width(n_width),m_Height(n_height),m_alloc(alloc)
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
//virtual void shape::setLocalOrigin(sf::Vector2f n_Origin)
//{}

	//draw method implementation
//virtual void shape::draw(sf::RenderTarget& target, sf::RenderStates states) const = 0
//{}

	

