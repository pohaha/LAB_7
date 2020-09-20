#pragma once
#include "common.h"
#include "originPoint.h"

enum RefreshOptions
{
	REFRESH_CONVEX_ONLY, REFRESH_ALL
};
class shape :
	public Point, sf::Drawable
{
public:	
	//data:
		//the dimensions of any figure that inherits from shape
	unsigned int m_Width = 0;
	unsigned int m_Height = 0;
	unsigned int m_pointCount=0;
	
	//c-tors,d-tors:
		//default c-tor
	shape();
	
		//parametr c-tors
	shape(unsigned int n_width, unsigned int n_height);
	shape(sf::Vector2u n_Dimensions);
	
		//copy c-tor
	shape(const shape& n_shape);

		//d-tor
	~shape();
	
	//methods to manipulate data
		//resize method
	void setSize(int n_height, int n_width);
	
		//setting the point at which the figure is being drawn at
	void setLocalOrigin(sf::Vector2f n_Origin);


	//interface methods:
		//draw function
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;
	


protected:
	//local origin that the figure is being drawn inside the shape
	sf::Vector2f LocalOrigin = { 0.f,0.f };
	
	//SFML array of consisting points for static allocation
	sf::ConvexShape m_Shape;

	//array of points for dynamic allocation
	sf::Vector2f* m_points=nullptr;

	//refreshes the points when the shape is changed
	virtual void refresh(sf::Vector2f* n_points,RefreshOptions OPT) = 0;
};

