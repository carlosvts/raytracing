#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

struct Renderer
{
    void Render(sf::RenderWindow& window, sf::Mouse& mouse, const std::vector<sf::CircleShape>& circleObstacles);
};
#endif