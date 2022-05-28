

#include <edge.hpp>


namespace MKbox2D
{
	Edge::Edge(b2World& physics_world, b2BodyType body_type, float x0, float y0, float x1, float y1)
    {
        b2BodyDef body_definition;

        body_definition.type = body_type;
        body_definition.position.Set(0.f, 0.f);                        

        body = physics_world.CreateBody(&body_definition);

        shape.SetTwoSided(b2Vec2(x0, y0), b2Vec2(x1, y1));

        b2FixtureDef body_fixture;

        body_fixture.shape = &shape;

        body->CreateFixture(&body_fixture);
    }
}