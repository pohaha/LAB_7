#pragma once
#include "common.h"
#include "originPoint.h"

enum allocType
{
	STATIC, DYNAMIC
};
class shape :
	public Point, sf::Drawable
{
public:	
	//data:
		//the dimensions of any figure that inherits from shape
	unsigned int m_Width = 0;
	unsigned int m_Height = 0;
	allocType m_alloc = STATIC;
	
	//c-tors,d-tors:
		//parametr c-tors
	shape(unsigned int&& n_width, unsigned int&& n_height, allocType alloc);
	shape(sf::Vector2u n_Dimensions, allocType alloc);
	
		//copy c-tor
	shape(const shape& n_shape);

		//d-tor
	~shape();
	
	//methods to manipulate data
		//resize method
	void setSize(int n_height, int n_width);
	
		//setting the point at which the figure is being drawn at
	virtual void setLocalOrigin(sf::Vector2f n_Origin);


	//interface methods:
		//draw function
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	

	// test methods::
	void setborder();

protected:
	//local origin that the figure is being drawn inside the shape
	sf::Vector2f LocalOrigin = { 0.f,0.f };
	
	//SFML array of consisting points for static allocation
	sf::ConvexShape m_Shape;

	//array of points for dynamic allocation
	sf::Vertex* m_points=nullptr;
	
};

