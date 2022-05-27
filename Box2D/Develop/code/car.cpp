


#include <car.hpp>


namespace MKbox2D
{
	Car::Car(b2World& physics_world, b2BodyType body_type, float x, float y, float radius, float width, float height)
	{
		chasis = new Cube(physics_world, body_type, x, y, width, height);
		wheel1 = new Circle(physics_world, body_type, x + width, y - height, radius);
		wheel2 = new Circle(physics_world, body_type, x - width, y - height, radius);

		speed = 20;

		b2RevoluteJointDef* joint1 = new b2RevoluteJointDef();
		joint1->bodyA = chasis->get_body();
		joint1->bodyB = wheel1->get_body();
		joint1->localAnchorA = chasis->get_shape()->m_centroid + b2Vec2(width, -height);
		joint1->localAnchorB = wheel1->get_shape()->m_p;
		joint1->collideConnected = false;
		joint1->enableMotor = true;
		joint1->maxMotorTorque = 10000;
		motor1 = (b2RevoluteJoint*)physics_world.CreateJoint(joint1);
		motor1->SetMotorSpeed(20);
		

		b2RevoluteJointDef* joint2 = new b2RevoluteJointDef();
		joint2->bodyA = chasis->get_body();
		joint2->bodyB = wheel2->get_body();
		joint2->localAnchorA = chasis->get_shape()->m_centroid + b2Vec2(-width, -height);
		joint2->localAnchorB = wheel2->get_shape()->m_p;
		joint2->collideConnected = false;
		joint2->enableMotor = true;
		joint2->maxMotorTorque = 10000;
		motor2 = (b2RevoluteJoint*)physics_world.CreateJoint(joint2);
		motor2->SetMotorSpeed(20);

	}

	void Car::Update() {}
}