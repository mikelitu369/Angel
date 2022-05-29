


#include <car.hpp>
#include <input.hpp>


namespace MKbox2D
{
	Car::Car(b2World& physics_world, b2BodyType body_type, float x, float y, float radius, float width, float height)
	{
		chasis = new Cube(physics_world, body_type, x, y, width, height);
		wheel1 = new Circle(physics_world, body_type, x + width, y - height, radius);
		wheel2 = new Circle(physics_world, body_type, x - width, y - height, radius);

		speed = 40;

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

		speed2 = 1 ;

		carretilla = new Carretilla(physics_world, body_type, x - width, y + 2*height, width*2, 1, 0.1);

		b2RevoluteJointDef* joint3 = new b2RevoluteJointDef();
		joint3->bodyA = chasis->get_body();
		joint3->bodyB = carretilla->get_body();
		joint3->localAnchorA = chasis->get_shape()->m_centroid + b2Vec2(-width, 2*height);
		joint3->localAnchorB = carretilla->get_base()->get_shape()->m_centroid + b2Vec2(-width, 0);
		joint3->collideConnected = false;
		joint3->enableMotor = true;
		joint3->enableLimit = true;
		joint3->maxMotorTorque = 10000;
		motor3 = (b2RevoluteJoint*)physics_world.CreateJoint(joint3);
		motor3->SetMotorSpeed(0);
		motor3->SetLimits(0, 3.14/2);


		body = chasis->get_body();
	}

	void Car::Update()
	{

		carretilla->Update();


		float speed_fixed = Utils::clamp(Input::instance().horizontal * speed, -speed, speed);		

		motor1->SetMotorSpeed(-speed_fixed);
		motor2->SetMotorSpeed(-speed_fixed);

		float speed_fixed2 = Utils::clamp(Input::instance().vertical * speed2, -speed2, speed2);

		motor3->SetMotorSpeed(speed_fixed2);
	}
}