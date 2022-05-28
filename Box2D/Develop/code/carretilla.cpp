



#include <carretilla.hpp>



namespace MKbox2D
{
	Carretilla::Carretilla(b2World& physics_world, b2BodyType body_type, float x, float y, float width, float height, float slim)
	{
		width /= 2;
		height /= 2;
		y += 1;
		slim /= 2;
		base = new Cube(physics_world, body_type, x+width/2, y+slim/2, width, slim);
		pared1 = new Cube(physics_world, body_type, x+slim/2, y + height/2, slim, height);
		pared2 = new Cube(physics_world, body_type, x + width + slim/2, y+height/2, slim, height);

		b2RevoluteJointDef* joint1 = new b2RevoluteJointDef();
		joint1->bodyA = base->get_body();
		joint1->bodyB = pared1->get_body();
		joint1->localAnchorA = base->get_shape()->m_centroid + b2Vec2(-width / 2, 0);
		joint1->localAnchorB = base->get_shape()->m_centroid + b2Vec2(-width / 2, 0);
		joint1->collideConnected = false;
		joint1->enableMotor = true;
		joint1->maxMotorTorque = 100000;
		clavo1 = (b2RevoluteJoint*)physics_world.CreateJoint(joint1);
		clavo1->SetMotorSpeed(0);

		b2RevoluteJointDef* joint2 = new b2RevoluteJointDef();
		joint2->bodyA = base->get_body();
		joint2->bodyB = pared2->get_body();
		joint2->localAnchorA = base->get_shape()->m_centroid + b2Vec2(width / 2, 0);
		joint2->localAnchorB = base->get_shape()->m_centroid + b2Vec2(width / 2, 0);
		joint2->collideConnected = false;
		joint2->enableMotor = true;
		joint2->maxMotorTorque = 100000;
		clavo2 = (b2RevoluteJoint*)physics_world.CreateJoint(joint1);
		clavo2->SetMotorSpeed(0);

		body = base->get_body();
	}

}