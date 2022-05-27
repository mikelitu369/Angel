


#include <cube.hpp>


namespace MKbox2D
{
	Cube::Cube(b2World& physics_world, b2BodyType body_type, float x, float y, float width, float height)
    {
        body_definition;

        body_definition.type = body_type;
        body_definition.position.Set(x, y);                            

        body = physics_world.CreateBody(&body_definition);


        body_shape.SetAsBox(width, height);


        body_fixture;

        body_fixture.shape = &body_shape;
        body_fixture.density = 1.00f;
        body_fixture.restitution = 0.50f;
        body_fixture.friction = 0.50f;

        body->CreateFixture(&body_fixture);
    }
}