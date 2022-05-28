

#pragma once

#include<object.hpp>
#include<circle.hpp>
#include<cube.hpp>
#include<carretilla.hpp>


namespace MKbox2D
{
	class Car : public Object
	{
	protected:

		Cube* chasis;
		Circle* wheel1;
		Circle* wheel2;
		b2RevoluteJoint* motor1;
		b2RevoluteJoint* motor2;

		Carretilla* carretilla;
		b2RevoluteJoint* motor3;

		float speed;
		float speed2;

	public:
		
		Car(b2World& physics_world, b2BodyType body_type, float x, float y, float radius, float width, float height);

		void Update();
	};
}