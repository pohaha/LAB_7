#include "triangle.h"

float min(sf::Vector2f* pointsArray, coord type);
float max(sf::Vector2f* pointsArray, coord type);





void triangle::refresh(sf::Vector2f* n_points,RefreshOptions OPT)
{
	//if(OPT == REFRESH_ALL)
		
	for (unsigned int i = 0; i < m_pointCount; i++)
	{
		if (OPT == REFRESH_ALL)
			m_points[i] = n_points[i] + position - LocalOrigin;
		m_Shape.setPoint(i, m_points[i]);
	}
	m_Shape.setPosition(position - LocalOrigin);	
}


triangle::triangle(int n_width, int n_height) :
	shape(n_width, n_height)
{
	if ((m_Width == 0) || (m_Height == 0))
	{
		std::cout << "all points of triangle cannot be on the same line!! LEARN MATH!" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_pointCount = 3;
	m_points = new sf::Vector2f[m_pointCount];
	m_points[0] = { 0,float(m_Height) };
	m_points[1] = { float(m_Width)/2,0 };
	m_points[2] = { float(m_Width),float(m_Height)};
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
void triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Shape);
}

