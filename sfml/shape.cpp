#include "shape.h"
#include "common.h"

shape::shape(float n_width, float n_height):
	m_Width(n_width),m_Height(n_height)
{}
shape::shape(sf::Vector2f n_Dimensions) :
	m_Width(n_Dimensions.x), m_Height(n_Dimensions.y)
{}
shape::shape(const shape& n_shape)
{

}
shape::~shape()
{

}


