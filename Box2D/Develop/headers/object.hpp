

#pragma once

#include <Box2D/Box2D.h>
#include <SFML\Graphics.hpp>
#include <utils.hpp>


namespace MKbox2D
{
	class Object
	{
	protected:
		b2Body* body = nullptr;
		b2BodyDef body_definition;
		b2FixtureDef body_fixture;

	public:

		virtual void Update() = 0;
		b2Body* get_body() { return body; }
	};
}