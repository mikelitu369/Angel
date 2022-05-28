
#pragma once

#include <box2d\box2d.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace MKbox2D
{
    class Utils
    {
    public:
        static sf::Vector2f box2d_position_to_sfml_position(const b2Vec2& box2d_position, float window_height, float scale)
        {
            return sf::Vector2f(box2d_position.x * scale, window_height - box2d_position.y * scale);
        }

        static b2Vec2 sfml_position_to_box2d_position(const sf::Vector2f& sfml_position, float window_height, float scale)
        {
            return b2Vec2(sfml_position.x / scale, (window_height - sfml_position.y) / scale);
        }

        static float clamp(float base, float min, float max)
        {
            if (base < min) return min;
            else if (base > max) return max;
            return base;
        }
    };
}