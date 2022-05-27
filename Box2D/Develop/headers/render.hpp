


#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <utils.hpp>


using namespace sf;

namespace MKbox2D
{
	class Render
	{
    public:
        static void render_circle
        (
            b2Vec2              center,
            float               radius,
            const b2Transform& transform,
            RenderWindow& renderer,
            float               window_height,
            float               scale
        );

        static void render_segment
        (
            const Vector2f& start,
            const Vector2f& end,
            const Color& color,
            RenderWindow& renderer
        );

        static void render_segment
        (
            b2Vec2              start,
            b2Vec2              end,
            const b2Transform& transform,
            RenderWindow& renderer,
            float               window_height,
            float               scale
        );

        static void render_polygon
        (
            const b2Vec2* vertices,
            int                 number_of_vertices,
            const b2Transform& transform,
            RenderWindow& renderer,
            float               window_height,
            float               scale
        );

        static void render(b2World& physics_world, RenderWindow& renderer, float scale);
	};
}