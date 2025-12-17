#include <SFML/Graphics.hpp>
#include <cmath>

#include "renderer.hpp"
#include "raytracing.hpp"

void Renderer::Render(sf::RenderWindow& window, sf::Mouse& mouse, const std::vector<sf::CircleShape>& circleObstacles)
{
    sf::VertexArray triangles(sf::TriangleFan);
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(mouse.getPosition(window));

    float lightRadius = 600.f;

    // Adding a gradient color for aesthetical reasons
    sf::Color centerColor = sf::Color(255, 248, 235, 255); // White
    sf::Color baseColor = sf::Color(255, 200, 120); // yellowish color WITHOUT alpha

    // adds the mouse position to the trianglefan
    triangles.append(sf::Vertex(mousePos, centerColor));
    
    sf::Vector2f finalPos;

    // 0.01 rads = 1 degree
    // cos = ca/h portanto cos = ca
    float thetaIncrease = 0.001f;
    for(float theta = 0.0f; theta <= 2.0f*M_PI ; theta += thetaIncrease)
    {
        // min distance
        float minDistance = lightRadius;
        bool hitSomething {false};

        // for radius = 1, this equation is true
        float xPos = cosf32(theta);
        float yPos = sinf32(theta);
        Ray ray;
        ray.origin = mousePos;
        ray.direction.x = xPos;
        ray.direction.y = yPos; 

        for(size_t i = 0; i < circleObstacles.size(); ++i)
        {
            // the actual circle
            const sf::CircleShape& circleShape = circleObstacles.at(i);

            // the circle for math equations
            Circle mathCircle;
            mathCircle.radius = circleShape.getRadius();
            mathCircle.centre = circleShape.getPosition();


            Hit hit;
            hit = calculateCricleIntersection(ray, mathCircle);
            if (hit.distance > -1 && hit.distance < minDistance)
            {
                minDistance = hit.distance;
                finalPos = hit.point;
                hitSomething = true;            
            }
        }

        // To apply the gradient effect only to the radius of the light
        float factor = minDistance / lightRadius; // Factor of distance that traveled until hit an object (or not)
        float intensity = 1.0f - factor; // get intensity of light
        if (intensity <= 0.0f) { intensity = 0.0f; }
        sf::Uint8 alpha = static_cast<sf::Uint8>(255 * intensity);

        if (!hitSomething)
        {
            minDistance = lightRadius;
            finalPos = ray.origin + (ray.direction * minDistance);
        }
        // applying alpha here
        sf::Color colorWithGradient = sf::Color(baseColor.r, baseColor.g, baseColor.b, alpha);
        triangles.append(sf::Vertex(finalPos, colorWithGradient));
    }
    window.draw(triangles);
}