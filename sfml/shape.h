#pragma once
#include "common.h"
#include "originPoint.h"
class shape :
	public Point, sf::Drawable
{
public:	
	//the dimensions of any figure that inherits from shape
	float m_Width = 0;
	float m_Height = 0;


	//parametr c-tors
	shape(float n_width, float n_height);
	shape(sf::Vector2f n_Dimensions);
	
	//copy c-tor
	shape(const shape& n_shape);

	//d-tor
	~shape();
	
	
	//setting the point at which the figure is being drawn at
	virtual void setLocalOrigin(sf::Vector2f n_Origin) {}

	//draw function
	sf::CircleShape n_draw() { return sf::CircleShape(50, 3); }


protected:
	//local origin that the figure is being drawn inside the shape
	sf::Vector2f LocalOrigin = { 0.f,0.f };
	
	//SFML array of consisting points for static allocation
	sf::ConvexShape m_Shape;

	//array of points for dynamic allocation
	sf::Vector2f* pointArray = NULL;
};

