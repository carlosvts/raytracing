#include <SFML/Graphics.hpp>
#include <cmath>

#include "raytracing.hpp"

// Utils
// performs a dot product between origin and destination
float dot(sf::Vector2f origin, sf::Vector2f destination)
{
    float dot = (origin.x * destination.x) + (origin.y * destination.y);
    return dot;
}

sf::Vector2f normalize(sf::Vector2f vector)
{
    float lenght = sqrtf32((vector.x * vector.x) + (vector.y * vector.y));
    if (lenght != 0)
    {
        return vector/lenght;
    }
    return vector;
}

// #################################################

Hit calculateCricleIntersection(Ray ray, Circle circle)
{
    // needs to evaluate everything as if the circle was in the origin
    sf::Vector2f localOrigin = ray.origin - circle.centre;

    Hit hit;

    // solving the quadratic equation
    // first we evalute a, b, c
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(localOrigin, ray.direction);
    float c = dot(localOrigin, localOrigin) - powf32(circle.radius, 2);
    
    // calculate the discriminant 
    float discriminant = powf32(b, 2) - (4 * a * c);
    if (discriminant < 0)
    {
        // didnt hit the circle
        hit.distance = -1;
        return hit;
    }
    if (discriminant >= 0)
    {
        // 2 hits (we'll take the lowest value, since is the first that will hit)
        // now actually solving the equation
        // -b +- sqrt(discriminant) /2a; we want only the negative since its the first that will hit
        // scalar t
        float t = (-b - sqrtf32(discriminant)) / (2.0f * a);
        if (t < 0)
        {
            // that means that the circle is behind our cast of light
            hit.distance = -1;
            return hit;
        }  
        // Calculating where the hit happened
        // Point = origin + direction * t
        hit.point = ray.origin + (ray.direction * t);

        // Calculating the normal point where the hit tangentiate the circle
        sf::Vector2f normal = hit.point - circle.centre;
        hit.angle = atan2(normal.y, normal.x);
        hit.distance = t;
        return hit;
    }
    hit.distance = -1;
    return hit;
}
