//for the usage of mathematical constants


//standart includes
#include <vector>


#include "common.h"

//user includes
#include "originPoint.h"
#include "shape.h"
#include "triangle.h"
#include "Ellyps.h"


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
    int speed = 1.f;
    triangle New_Triangle(100, 200);
    New_Triangle.setLocalOrigin({ 50,100 });
    std::cout << "triangle created" << std::endl;
    Ellyps New_Ellyps(window.getSize().x, window.getSize().y, 360);
    sf::Text text;
    sf::Font newfont;
    if (!newfont.loadFromFile("consola.ttf"))
    {
        std::cout << "error loading font!" << std::endl;
        window.close();
    }
    text.setFont(newfont);
    text.setString("the current position is:\n" + New_Ellyps.show() + "\npoint count is: " + std::to_string(New_Ellyps.m_pointCount));
    text.setPosition(windowSize.x - text.getGlobalBounds().width - 10, windowSize.y - text.getGlobalBounds().height - 15);
    int count = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update
        if (count < ((New_Ellyps.m_pointCount) - 1))

            New_Triangle.move(New_Ellyps.m_points[count] - New_Triangle.position);
        else
            count = 0;

        count += speed;

        text.setString("the current position is:\n" + New_Triangle.show() + "\npoint count is: " + std::to_string(count));

        //clear
        window.clear();

        //set stuff up
        New_Triangle.draw(window, sf::RenderStates::Default);
        window.draw(text);



        //display stuff on screen
        window.display();
    }

    return 0;
}