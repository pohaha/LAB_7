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
void shape::setLocalOrigin(const sf::Vector2f n_Origin)
{
	LocalOrigin = n_Origin;
}

//interface methods
	//draw function
void shape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Shape);
}

void shape::refresh(sf::Vector2f* n_points, RefreshOptions OPT)
{

	for (unsigned int i = 0; i < m_pointCount; i++)
	{
		if (OPT == REFRESH_ALL)
			m_points[i] = n_points[i] + position-LocalOrigin;
		m_Shape.setPoint(i, m_points[i]);
	}
	m_Shape.setPosition(position - LocalOrigin);
	

}
void shape::move(const sf::Vector2f& step)
{
	position += step;
	refresh(m_points, REFRESH_CONVEX_ONLY);
}



	

