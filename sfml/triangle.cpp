#include "triangle.h"

float min(sf::Vertex* pointsArray, coord type);
float max(sf::Vertex* pointsArray, coord type);


triangle::triangle(int n_width, int n_height) :
	shape(n_width, n_height)
{

}
triangle::triangle(sf::Vector2f point_A, sf::Vector2f point_B, sf::Vector2f point_C)
{
	m_pointCount = 3;
	if (((point_A.x == point_B.x) && (point_B.x == point_C.x)) || ((point_A.y == point_B.y) && (point_B.x == point_C.y)))
	{
		std::cout << "all points of triangle cannot be on the same line!! LEARN MATH!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		m_points = new sf::Vertex[m_pointCount];
		m_Shape.setPointCount(m_pointCount);
		m_points[0] = sf::Vertex(point_A + position - LocalOrigin);
		m_points[1] = sf::Vertex(point_B + position - LocalOrigin);
		m_points[2] = sf::Vertex(point_C + position - LocalOrigin);
		m_Shape.setPoint(0,point_A);
		m_Shape.setPoint(1, point_B);
		m_Shape.setPoint(2, point_C);
		m_Shape.setPosition(position-LocalOrigin);
		m_Width = max(m_points, s_x) - min(m_points, s_x);
		m_Height = max(m_points, s_y) - min(m_points, s_y);

		
	}
}
void triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}