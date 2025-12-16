#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

constexpr uint32_t WIDTH = 1000;
constexpr uint32_t HEIGHT = 800;



int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Raytracing");

    std::vector<sf::CircleShape> circleObstacles;
    std::vector<sf::RectangleShape> rectObstacles;

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