#include "shape.h"
#include "common.h"


class triangle :
	public shape
{
public:
	//c-tors
		//width/height c-tor
	triangle(int n_width, int n_height);

		//point c-tor
	triangle(sf::Vector2f* n_points);

		//equal sides constructor

	triangle(float eqal_side);
	void test(int i);

};