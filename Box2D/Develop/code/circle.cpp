


#include <circle.hpp>

namespace MKbox2D
{
	Circle::Circle(b2World& physics_world, b2BodyType body_type, float x, float y, float radius)
	{
        {
            // Se crea el body:
            body_definition.type = body_type;
            body_definition.position.Set(x, y);                            

            body = physics_world.CreateBody(&body_definition);

            // Se añande una fixture:
            body_shape.m_radius = radius;

            body_fixture.shape = &body_shape;
            body_fixture.density = 1.00f;
            body_fixture.restitution = 0.75f;
            body_fixture.friction = 0.50f;

            body->CreateFixture(&body_fixture);
        }
	}
}