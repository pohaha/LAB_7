#include "shape.h"
#include "common.h"

//c-tors, d-tors implementation:
	//parametr c-tors
shape::shape(unsigned int&& n_width, unsigned int&& n_height, allocType alloc = STATIC) :
	shape::m_Width(n_width),shape::m_Height(n_height),shape::m_alloc(alloc)
{}
shape::shape(sf::Vector2u n_Dimensions, allocType alloc = STATIC) : 
	m_Width(n_Dimensions.x), m_Height(n_Dimensions.y),m_alloc(alloc)
{}

	//copy c-tor
shape::shape(const shape& n_shape)
{
	shape::LocalOrigin = n_shape.LocalOrigin;
	shape::m_Shape = n_shape.m_Shape;
	shape::m_points = n_shape.m_points;
}

	//d-tor
shape::~shape()
{

}

//manip methods implementation
	//resize method implementation
void shape::setSize(int n_height, int n_width)
{
	m_Height = n_height;
	m_Width = n_width;
}

	//set origin implementation
void shape::setLocalOrigin(sf::Vector2f n_Origin)
{ 
	LocalOrigin = n_Origin;
}

//--TEST--
	//setborder method implementation
void shape::setborder()
{
	shape::m_Shape.setPointCount(4);
	shape::m_Shape.setPoint(0, position);
	shape::m_Shape.setPoint(1, position + sf::Vector2f(float(m_Width), 0));
	shape::m_Shape.setPoint(2, position + sf::Vector2f(float(m_Width), float(m_Height)));
	shape::m_Shape.setPoint(3, position + sf::Vector2f(0, float(m_Height)));
	shape::m_Shape.setOutlineColor(sf::Color::White);
	shape::m_Shape.setFillColor(sf::Color::Transparent);
	shape::m_Shape.setOutlineThickness(1);
}
	//draw method implementation
void shape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Text text;
	std::string mess("this is the area of a future figure\n");
	text.setString("this is the local origin of a shape\n\n"+mess+"that'll be drawn inside");
	sf::Font newfont;
	newfont.loadFromFile("consola.ttf");
	text.setFont(newfont);
	int size(m_Width / (mess.length() + 6));
	text.setCharacterSize(size*2);
	text.setPosition(position.x+text.getCharacterSize(),position.y+LocalOrigin.y+text.getCharacterSize()+3);
	target.draw(text);
	
	
	sf::CircleShape originPoint(3);
	originPoint.setOrigin(originPoint.getRadius(), originPoint.getRadius());
	originPoint.setFillColor(sf::Color::Green);
	originPoint.setPosition(position+LocalOrigin);
	target.draw(originPoint);
	
	

	
	sf::Vertex line_one[] =
	{
		sf::Vertex(originPoint.getPosition() 
					//	+ sf::Vector2f(3, 3)
		),
		sf::Vertex(text.getPosition())
	};
	target.draw(line_one, 2, sf::Lines);

	
	sf::Vertex line_two[] =
	{
		sf::Vertex(shape::m_Shape.getPoint(2)),
		sf::Vertex(text.getPosition() + sf::Vector2f(text.getGlobalBounds().width-7*text.getCharacterSize()+3, text.getGlobalBounds().height+5))
	};
	target.draw(line_two,2,sf::Lines);

	target.draw(shape::m_Shape);
}

	

