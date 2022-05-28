



#include <carretilla.hpp>



namespace MKbox2D
{
	Carretilla::Carretilla(b2World& physics_world, b2BodyType body_type, float x, float y, float width, float height, float slim)
	{
		recoveriSpeed = 0.01f;

		slim /= 4;
		base = new Cube(physics_world, body_type, x+width/4, y+slim/2, width/2, slim);
		pared1 = new Cube(physics_world, body_type, x+slim/2, y + height/4, slim, height/2);
		pared2 = new Cube(physics_world, body_type, x + width/2 + slim/2, y+height/2, slim, height/2);

		b2RevoluteJointDef* joint1 = new b2RevoluteJointDef();
		joint1->bodyA = base->get_body();
		joint1->bodyB = pared1->get_body();
		joint1->localAnchorA = base->get_shape()->m_centroid + b2Vec2(-width / 2, 0);
		joint1->localAnchorB = pared1->get_shape()->m_centroid + b2Vec2(0, -height/2);
		joint1->collideConnected = false;
		joint1->enableMotor = true;
		joint1->enableLimit = true;
		joint1->maxMotorTorque = 100000;
		clavo1 = (b2RevoluteJoint*)physics_world.CreateJoint(joint1);
		clavo1->SetMotorSpeed(0);
		clavo1->SetLimits(0, 0);

		b2RevoluteJointDef* joint2 = new b2RevoluteJointDef();
		joint2->bodyA = base->get_body();
		joint2->bodyB = pared2->get_body();
		joint2->localAnchorA = base->get_shape()->m_centroid + b2Vec2(width / 2, 0);
		joint2->localAnchorB = pared2->get_shape()->m_centroid + b2Vec2(0, -height / 2);
		joint2->collideConnected = false;
		joint2->enableMotor = true;
		joint2->enableLimit = true;
		joint2->maxMotorTorque = 100000;
		clavo2 = (b2RevoluteJoint*)physics_world.CreateJoint(joint2);
		clavo2->SetMotorSpeed(0);
		clavo2->SetLimits(0, 0);

		body = base->get_body();
	}


	void Carretilla::Update()
	{
		float margin = 0.02f;
		float speed1 = 0;
		float speed2 = 0;

		if (clavo1->GetAnchorB().x - pared1->get_shape()->m_centroid.x < -margin) speed1 = recoveriSpeed;
		else if (clavo1->GetAnchorB().x - pared1->get_shape()->m_centroid.x > margin) speed1 = -recoveriSpeed;
		clavo1->SetMotorSpeed(speed1);


		if (clavo2->GetAnchorB().x - pared2->get_shape()->m_centroid.x < -margin) speed2 = recoveriSpeed;
		else if (clavo2->GetAnchorB().x - pared2->get_shape()->m_centroid.x > margin) speed2 = -recoveriSpeed;
		clavo2->SetMotorSpeed(speed2);

	}
}