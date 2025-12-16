#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <SFML/Graphics.hpp>

struct Ray
{
    // origin of the point of light emiting
    sf::Vector2f origin {};
    // "ending point"
    sf::Vector2f direction {};
};

// In this ray tracing simulation the user will be able to place walls and spheres on the map

struct Wall 
{
    // user defined struct that a shadow will be casted on
    // contains coordinates of two points
    sf::Vector2f a;
    sf::Vector2f b;
};

struct Circle
{
    sf::Vector2f centre;
    float radius;
};

struct Hit
{
    sf::Vector2f point;
    float distance;
    float angle;
};

#endif