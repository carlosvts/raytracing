#include <iostream>
#include <SFML/Graphics.hpp>

constexpr uint WIDTH = 1000;
constexpr uint HEIGHT = 800;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Raytracing");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
        window.clear();
        // window.draw();
        window.display();
    }

    return 0;
}