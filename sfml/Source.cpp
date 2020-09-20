//for the usage of mathematical constants
#define _USE_MATH_DEFINES

//standart includes
#include <vector>
#include "math.h"

#include "common.h"

//user includes
#include "originPoint.h"
#include "shape.h"
#include "triangle.h"


float min(sf::Vector2f* pointsArray, coord type)
{
    float returnVal;
    if (type == s_x)
    {
        returnVal = pointsArray[0].x;
        for (int i = 1; i < 2; i++)
            if (returnVal > pointsArray[i].x)
                returnVal = pointsArray[i].x;
    }
    else
    {
        returnVal = pointsArray[0].y;
        for (int i = 1; i < 2; i++)
            if (returnVal > pointsArray[i].y)
                returnVal = pointsArray[i].y;
    }
    return returnVal;
}

float max(sf::Vector2f* pointsArray, coord type)
{
    float returnVal;
    if (type == s_x)
    {
        returnVal = pointsArray[0].x;
        for (int i = 1; i < 2; i++)
            if (returnVal < pointsArray[i].x)
                returnVal = pointsArray[i].x;
    }
    else
    {
        returnVal = pointsArray[0].y;
        for (int i = 1; i < 2; i++)
            if (returnVal < pointsArray[i].y)
                returnVal = pointsArray[i].y;
    }
    return returnVal;
}



int main()
{
    sf::Vector2u windowSize = { 1900,800 };
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");
    window.setFramerateLimit(60);

    sf::Vector2f* trianglePoints = new sf::Vector2f[3];
    trianglePoints[0] = sf::Vector2f(0, 60);
    trianglePoints[1] = sf::Vector2f(100, 70);
    trianglePoints[2] = sf::Vector2f(50, 30);

    triangle triangle_one(trianglePoints);
    int count = 0;
    sf::Vector2f step = { 1.f, 1.f };
    bool flag = false;
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
        
        if ((count % 100) == 0)     flag = !flag;        
        if (flag)                   triangle_one.move(step);
        else                        triangle_one.move(-step);

        count++;

        //clear
        window.clear();

        //set stuff up
        triangle_one.draw(window, sf::RenderStates::Default);

        //display stuff on screen
        window.display();
    }

    return 0;
}