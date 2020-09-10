//for the usage of mathematical constants
#define _USE_MATH_DEFINES

//standart includes
#include <vector>
#include <iostream>
#include "math.h"

//library includes
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

//user includes
#include "originPoint.h"

int main()
{
    sf::Vector2u windowSize = {1900,800};
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");
    window.setFramerateLimit(60);
    float radius = 30.f;
    float speed = 1.f;
    sf::CircleShape shape(radius,3);
    shape.setPosition(float(windowSize.x)/2, float(windowSize.y )/ 2);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius,radius);
    std::vector<sf::Vector2f> Ellyps;
    for (float parametr = 0; parametr < 360; parametr += 1)
        Ellyps.push_back({ ((float(windowSize.x) / 2) - 100) * float(cos(2 * M_PI / 360 * parametr)) + (float(windowSize.x) / 2),
                           ((float(windowSize.y) / 2) - 100) * float(sin(2 * M_PI / 360 * parametr)) + (float(windowSize.y) / 2) 
                        });

   
    originPoint NewPoint = { sf::Vector2f(window.getSize()) };

    sf::Text text;
    text.setString(NewPoint.show());
    sf::Font newfont;
    if (!newfont.loadFromFile("C:\\Windows\\Fonts\\consola.ttf"))
    {
        std::cout << "error loading font!"<<std::endl;
        window.close();
    }
    text.setFont(newfont);
    NewPoint = originPoint(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height));
    text.setString("the current position is:\n"+NewPoint.show()+"\npoint count is: "+std::to_string(Ellyps.size()));
    text.setPosition(windowSize.x-text.getGlobalBounds().width-10, windowSize.y - text.getGlobalBounds().height-15);
   
    float count = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update
        //shape.rotate(.50f);
       if (count < Ellyps.size())
            shape.setPosition(sf::Vector2f({ Ellyps[unsigned int(count)].x, Ellyps[unsigned int(count)].y }));
       else 
           count = 0;
        
       count += speed;
       
        //clear
        window.clear();

        //set stuff up
        window.draw(shape);
        window.draw(text);
        
        

        //display stuff on screen
        window.display();
    }

    return 0;
}