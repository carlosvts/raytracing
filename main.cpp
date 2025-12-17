#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "raytracing.hpp"
#include "renderer.hpp"

constexpr uint32_t WIDTH = 1000;
constexpr uint32_t HEIGHT = 800;


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Raytracing");
    sf::Mouse mouse;

    std::vector<sf::CircleShape> circleObstacles;
    std::vector<sf::RectangleShape> rectObstacles;

    sf::Font font;
    if (!font.loadFromFile("UniverseCondensed.ttf"))
    {
        std::cerr << "Error while using font. Are you sure he are in the program files?" << std::endl;
    }

    // set fps text
    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::Green);
    fpsText.setPosition(WIDTH - 100.f, HEIGHT - 100.f);

    // Set clock for fps metric
    sf::Clock clock;

    // framerate limit
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        Renderer renderer;

        sf::Time timeElapsed = clock.restart();
        float deltaTime = timeElapsed.asSeconds();
        float fps = 1.0f / deltaTime; // frames per second lol

        fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::CircleShape circle; 
                float radius = 30;
                circle.setRadius(radius);
                circle.setOrigin(radius, radius);
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(static_cast<sf::Vector2f>(mouse.getPosition(window)));
                circleObstacles.push_back(circle);
            }
        }
        window.clear();
        // draw light
        renderer.Render(window, mouse, circleObstacles);

        // draw fps
        window.draw(fpsText);

        // draw the circle at the top of the light
        for(const auto& circle : circleObstacles)
        {
            window.draw(circle);
        }

        window.display();
    }

    return 0;
}