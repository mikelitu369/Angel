

#pragma once

#include<object.hpp>
#include<circle.hpp>
#include<cube.hpp>


namespace MKbox2D
{
	class Car : public Object
	{
	protected:

		Cube* chasis;
		Circle* wheel1;
		Circle* wheel2;

	public:
		
		Car(b2World& physics_world, b2BodyType body_type, float x, float y, float radius, float width, float height);

		void Render(sf::RenderWindow& renderer, float window_height);

		void Update();
	};
}