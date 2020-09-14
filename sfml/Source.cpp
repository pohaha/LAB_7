//for the usage of mathematical constants
#define _USE_MATH_DEFINES

//standart includes
#include <vector>
#include <iostream>
#include "math.h"

#include "common.h"

//user includes
#include "originPoint.h"
#include "shape.h"

int main()
{
    sf::Vector2u windowSize = {1900,800};
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");
    window.setFramerateLimit(60);
    shape someshape(unsigned int(300), unsigned int(300),STATIC);
    sf::Vector2f pos(50.f, 50.f);
    someshape.setPos(pos);
    someshape.setborder();
    someshape.setLocalOrigin(sf::Vector2f(150.f, 150.f));

   
  
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
       
       
        //clear
        window.clear();

        //set stuff up
        //window.draw(shape);
        someshape.draw(window,sf::RenderStates::Default);
        
        

        //display stuff on screen
        window.display();
    }

    return 0;
}