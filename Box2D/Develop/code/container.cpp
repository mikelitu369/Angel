


#include <container.hpp>


namespace MKbox2D
{
	Container::Container(b2World& physics_world, Car* ref, float x, float y, float height, float width, int balls)
	{
		base = new Cube(physics_world, b2_kinematicBody, x, y, 0.02, 0.02);
		Carretilla* carretilla = new Carretilla(physics_world, b2_dynamicBody, x - width / 2, y, height, width, 0.05);


		b2RevoluteJointDef* motordeff = new b2RevoluteJointDef();
		motordeff->bodyA = base->get_body();
		motordeff->bodyB = carretilla->get_body();
		motordeff->localAnchorA = base->get_shape()->m_centroid;
		motordeff->localAnchorB = carretilla->get_base()->get_shape()->m_centroid;
		motordeff->collideConnected = false;
		motordeff->enableMotor = true;
		motordeff->enableLimit = true;
		motordeff->maxMotorTorque = 10000;
		motor = (b2RevoluteJoint*)physics_world.CreateJoint(motordeff);
		motor->SetMotorSpeed(0);
		motor->SetLimits(-3.2 / 2, 0);
		 
		speed = 0.2f;

		for (int i = 0; i < balls; i++)
		{
			new Circle(physics_world, b2_dynamicBody, x, y + height / 2, 0.1f);
		}

		reference = ref;
	}

	void Container::Update()
	{
		bool debug = reference->Get_position().x > base->get_body()->GetPosition().x;
		float f = reference->Get_position().x;
		float ff = base->get_body()->GetPosition().x;
		if (reference->Get_position().x > base->get_body()->GetPosition().x) motor->SetMotorSpeed(-speed);
	}
}