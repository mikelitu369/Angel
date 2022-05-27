


#pragma once

#include <object.hpp>


namespace MKbox2D
{
	class Cube : public Object
	{
	protected:

		b2PolygonShape body_shape;

	public:

		Cube(b2World& physics_world, b2BodyType body_type, float x, float y, float width, float height);

		void Update() {}

		b2PolygonShape* get_shape() { return &body_shape; }

	};
}