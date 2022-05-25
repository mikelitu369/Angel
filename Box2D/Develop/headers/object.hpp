

#pragma once

#include <Box2D/Box2D.h>
#include <SFML\Graphics.hpp>
#include <utils.hpp>


namespace MKbox2D
{
	class Object
	{
	protected:
		b2Body* body;
		b2BodyDef body_definition;
		b2FixtureDef body_fixture;

	public:

		virtual void Render(sf::RenderWindow& renderer, float window_height) = 0;
		virtual void Update() = 0;
	};
}