


#include <car.hpp>


namespace MKbox2D
{
	Car::Car(b2World& physics_world, b2BodyType body_type, float x, float y, float radius, float width, float height)
	{
		chasis = new Cube(physics_world, body_type, x, y, width, height);
		wheel1 = new Circle(physics_world, body_type, x + width, y - height, radius);
		wheel2 = new Circle(physics_world, body_type, x - width, y - height, radius);

	}

	void Car::Render(sf::RenderWindow& renderer, float window_height)
	{
		chasis->Render(renderer, window_height);
		wheel1->Render(renderer, window_height);
		wheel2->Render(renderer, window_height);
	}

	void Car::Update() {}
}