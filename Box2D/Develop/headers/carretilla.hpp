

#pragma once

#include<object.hpp>
#include<cube.hpp>


namespace MKbox2D
{
	class Carretilla : public Object
	{
	protected:

		Cube* base;
		Cube* pared1;
		Cube* pared2;

		b2RevoluteJoint* clavo1;
		b2RevoluteJoint* clavo2;	

		float recoveriSpeed;
		
	public:

		Carretilla(b2World& physics_world, b2BodyType body_type, float x, float y, float width, float height, float slim);

		void Update();

		Cube* get_base() { return base; }

	};
}