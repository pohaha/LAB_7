#include "shape.h"
#include "common.h"

class triangle :
	public shape
{
	//c-tors
		//width/height c-tor
	triangle(int n_width, int n_height);

		//point c-tor
	triangle(sf::Vector2f point_A, sf::Vector2f point_B, sf::Vector2f point_C);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};