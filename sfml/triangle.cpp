#include "triangle.h"


float min(sf::Vector2f* pointsArray, coord type);
float max(sf::Vector2f* pointsArray, coord type);








triangle::triangle(const int n_width, const int n_height) :
	shape(n_width, n_height)
{
	if ((m_Width == 0) || (m_Height == 0))
	{
		std::cout << "all points of triangle cannot be on the same line!! LEARN MATH!" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_pointCount = 3;
	delete[] m_points;
	m_points = new sf::Vector2f[m_pointCount];
	m_Shape.setPointCount(3);
	m_points[0] = sf::Vector2f( 0,float(m_Height))-LocalOrigin;
	m_points[1] = sf::Vector2f(float(m_Width)/2,0 )-LocalOrigin;
	m_points[2] = sf::Vector2f(float(m_Width),float(m_Height))-LocalOrigin;
	refresh(m_points, REFRESH_CONVEX_ONLY);

}
triangle::triangle(sf::Vector2f* n_points)
{
	m_pointCount = 3;
	if (((n_points[0].x == n_points[1].x) && (n_points[1].x == n_points[2].x)) || ((n_points[0].y == n_points[1].y) && (n_points[1].x == n_points[2].y)))
	{
		std::cout << "all points of triangle cannot be on the same line!! LEARN MATH!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		m_points = new sf::Vector2f[m_pointCount];
		m_Shape.setPointCount(m_pointCount);
		refresh(n_points,REFRESH_ALL);
		m_Width = max(m_points, s_x) - min(m_points, s_x);
		m_Height = max(m_points, s_y) - min(m_points, s_y);
	}
}
triangle::triangle(float eqal_side)
{
	m_pointCount = 3;
	m_points = new sf::Vector2f[m_pointCount];
	m_Shape.setPointCount(m_pointCount);
	m_points[0] = sf::Vector2f(0, 0);
	m_points[1] = sf::Vector2f(eqal_side/2, eqal_side*sqrt(3)/2);
	m_points[0] = sf::Vector2f(eqal_side, 0);
	refresh(m_points, REFRESH_CONVEX_ONLY);
	m_Width = max(m_points, s_x) - min(m_points, s_x);
	m_Height = max(m_points, s_y) - min(m_points, s_y);
}

void triangle::test(int i)
{
	std::cout <<"convex point is "<< "  " << m_Shape.getPoint(i).y << std::endl;
	std::cout << show() << std::endl;
}
