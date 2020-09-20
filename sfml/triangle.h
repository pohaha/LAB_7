#include "shape.h"
#include "common.h"

class triangle :
	public shape
{
	//c-tors
		//width/height c-tor
	triangle(int n_width, int n_height);

		//point c-tor
	triangle(sf::Vector2f* n_points);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual void refresh(sf::Vector2f* n_points) override;

};