


#pragma once


#include <object.hpp>


namespace MKbox2D
{
	class Circle : public Object
	{
	protected:
		b2CircleShape body_shape;

	public:
		Circle(b2World& physics_world, b2BodyType body_type, float x, float y, float radius);

		void Render(sf::RenderWindow& renderer, float window_height);

		void Update() {}

		b2CircleShape* get_shape() { return &body_shape; }

	};
}