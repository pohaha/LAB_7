#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    window.setFramerateLimit(120);
    float radius = 30.f;
    int speed = 60;
    sf::CircleShape shape(radius,3);
    shape.setPosition(950, 500);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius,radius);
    std::vector<sf::Vector2f> Ellyps;
    double res;
    for (double i = 0; i < window.getSize().x; i+=0.1)
        for (double j = 0; j < window.getSize().y; j += 0.1)
        {
            res = pow((i-950),2) / pow(850, 2) + pow((j-500),2) / pow(400, 2);
            if((res < 1.f) && (res > .9f))
            {
                Ellyps.push_back({ float(i),float(j) });
                break;
            }
        }

   
    unsigned int count = 0;
    int filter = 1;
    int start = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update
        //hape.rotate(.50f);
        if ((count < Ellyps.size()) && (count >= 0))
            shape.setPosition(sf::Vector2f({ Ellyps[count].x, (start + (Ellyps[count].y) * filter) }));
        else
        {
            filter *= -1;
            if (filter < 0) start = 1000;
            else start = 0;
        }
        count += filter*speed;
        
        
        //clear
        window.clear();

        //set stuff up
        window.draw(shape);
        

        //display stuff on screen
        window.display();
    }

    return 0;
}