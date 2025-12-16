#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

class Renderer
{
    private:

    public:
        Renderer();

        void Renderer::Render(sf::RenderWindow& window, const std::vector<sf::CircleShape>& circleObstacles);
};
#endif