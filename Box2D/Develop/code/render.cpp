

#include <render.hpp>


namespace MKbox2D
{
    void Render::render_circle
    (
        b2Vec2              center,
        float               radius,
        const b2Transform& transform,
        RenderWindow& renderer,
        float               window_height,
        float               scale
    )
    {
        CircleShape shape;

        radius *= scale;

        shape.setPosition(Utils::box2d_position_to_sfml_position(b2Mul(transform, center), window_height, scale) - Vector2f(radius, radius));
        shape.setRadius(radius);
        shape.setFillColor(Color::Blue);

        renderer.draw(shape);
    }

    void Render::render_segment
    (
        const Vector2f& start,
        const Vector2f& end,
        const Color& color,
        RenderWindow& renderer
    )
    {
        Vertex line[] =
        {
            Vertex(start, color),
            Vertex(end, color),
        };

        renderer.draw(line, 2, Lines);
    }

    void Render::render_segment
    (
        b2Vec2              start,
        b2Vec2              end,
        const b2Transform& transform,
        RenderWindow& renderer,
        float               window_height,
        float               scale
    )
    {
        start = b2Mul(transform, start);
        end = b2Mul(transform, end);

        render_segment
        (
            Utils::box2d_position_to_sfml_position(start, window_height, scale),
            Utils::box2d_position_to_sfml_position(end, window_height, scale),
            Color::Green,
            renderer
        );
    }

    void Render::render_polygon
    (
        const b2Vec2* vertices,
        int                 number_of_vertices,
        const b2Transform& transform,
        RenderWindow& renderer,
        float               window_height,
        float               scale
    )
    {
        ConvexShape sfml_polygon;

        sfml_polygon.setPointCount(number_of_vertices);
        sfml_polygon.setFillColor(Color::Yellow);

        for (int index = 0; index < number_of_vertices; index++)
        {
            sfml_polygon.setPoint
            (
                index,
                Utils::box2d_position_to_sfml_position(b2Mul(transform, vertices[index]), window_height, scale)
            );
        }

        renderer.draw(sfml_polygon);
    }

    void Render::render(b2World& physics_world, RenderWindow& renderer, float scale)
    {
        float window_height = (float)renderer.getSize().y;

        for (b2Body* body = physics_world.GetBodyList(); body != nullptr; body = body->GetNext())
        {
            const b2Transform& body_transform = body->GetTransform();

            for (b2Fixture* fixture = body->GetFixtureList(); fixture != nullptr; fixture = fixture->GetNext())
            {
                b2Shape::Type shape_type = fixture->GetShape()->GetType();

                switch (shape_type)
                {
                case b2Shape::e_circle:
                {

                    b2CircleShape* circle = dynamic_cast<b2CircleShape*>(fixture->GetShape());

                    render_circle(circle->m_p, circle->m_radius, body_transform, renderer, window_height, scale);

                    break;
                }

                case b2Shape::e_edge:
                {

                    b2EdgeShape* edge = dynamic_cast<b2EdgeShape*>(fixture->GetShape());

                    render_segment(edge->m_vertex1, edge->m_vertex2, body_transform, renderer, window_height, scale);

                    break;
                }

                case b2Shape::e_polygon:
                {

                    b2PolygonShape* box2d_polygon = dynamic_cast<b2PolygonShape*>(fixture->GetShape());

                    render_polygon(box2d_polygon->m_vertices, box2d_polygon->m_count, body_transform, renderer, window_height, scale);

                    break;
                }
                }
            }
        }
    }
}