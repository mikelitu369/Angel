

#pragma once


#include <object.hpp>
#include <circle.hpp>
#include <car.hpp>
#include <carretilla.hpp>
#include <cube.hpp>

namespace MKbox2D
{
	class Container : public Object
	{
	protected:

		b2RevoluteJoint* motor;
		Car* reference;
		Cube* base;

		float speed;

	public:

		Container(b2World& physics_world, Car* ref, float x, float y, float height, float width, int balls);

		void Update();
	};
}