


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

		/*
		b2DistanceJointDef* joint1 = new b2DistanceJointDef();
		joint1->Initialize(chasis->get_body(), wheel1->get_body(), wheel1->get_shape()->m_p, wheel1->get_shape()->m_p);
		joint1->length = 0;
		joint1->collideConnected = false;
		joint1->stiffness = 15.0f;
		joint1->damping = 150.0f;
		b2DistanceJoint joint01(joint1);		
		b2DistanceJointDef* joint2 = new b2DistanceJointDef();
		joint2->Initialize(chasis->get_body(), wheel2->get_body(), wheel2->get_shape()->m_p, wheel2->get_shape()->m_p);
		joint2->length = 0;
		*/

	}

	void Car::Update() {}
}