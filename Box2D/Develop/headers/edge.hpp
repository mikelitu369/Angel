

#pragma once

#include <object.hpp>

namespace MKbox2D
{
	class Edge : public Object
	{
	private:

		b2EdgeShape shape;

	public:

		Edge(b2World& physics_world, b2BodyType body_type, float x0, float y0, float x1, float y1);

		void Update() {}

		b2EdgeShape* Get_shape() { return &shape; }

		void Move(b2Vec2 vector);
	};
}