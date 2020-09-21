#pragma once
#include "shape.h"
#include "common.h"
class Ellyps :
	public shape
{
public:
	//data
		//number of points of a figure
	//c-tors,d-tors
		//default c-tor
	Ellyps();

		//parametr c-tors
	Ellyps(unsigned int n_width, unsigned int n_height, int Resolution = 360);

		//copy c-tor
	Ellyps(const Ellyps & n_Ellyps);

		//d-tor
	~Ellyps();

private:

};

