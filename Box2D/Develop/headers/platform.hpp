

#pragma once

#include <edge.hpp>
#include <car.hpp>
#include <object.hpp>

namespace MKbox2D
{
	class Platform : public Object
	{
	protected:

		float pos0;
		float pos1;
		float pos2;

		Car* referencia;

		Edge* base;
		Edge* pared1;
		Edge* pared2;

		float* activePosition;

		float speed;
		float xref;
		float actual_y;

	public:

		Platform(b2World& physics_world, b2BodyType body_type, Car* ref, float x0, float x1, float pos0, float pos1, float pos2);

		void Update();
	};
}

