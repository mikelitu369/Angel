


#include <platform.hpp>


namespace MKbox2D
{
	Platform::Platform(b2World& physics_world, b2BodyType body_type, Car* ref, float x0, float x1, float pos0, float pos1, float pos2)
	{
		base = new Edge(physics_world, body_type, x0, pos0, x1, pos0);
		pared1 = new Edge(physics_world, body_type, x0, pos0, x0, pos0 - pos2);
		pared2 = new Edge(physics_world, body_type, x1, pos0, x1, pos0 - pos2);

		referencia = ref;

		this->pos0 = pos0;
		this->pos1 = pos1;
		this->pos2 = pos2;

		activePosition = &pos0;

		speed = 0.01f;
		xref = (x0 + x1) / 2.0f;
		actual_y = pos0;

		body = base->get_body();
	}

	void Platform::Update()
	{
		float margen = 0.5;
		float diferencia = referencia->Get_position().x - xref;
		if (diferencia > margen) activePosition = &pos1;
		else if (diferencia < margen && diferencia > -margen) activePosition = &pos2;
		else activePosition = &pos0;

		if (referencia->Get_position().y > pos2) activePosition = &pos2;


		float direction = 1;
		if (actual_y > *activePosition) direction *= -1;
		float difference = actual_y - *activePosition;
		if (difference < 0.01f && difference > -0.01f) direction = 0;

		base->Move(b2Vec2(0, speed * direction));
		pared1->Move(b2Vec2(0, speed * direction));
		pared2->Move(b2Vec2(0, speed * direction));
		actual_y += (speed * direction);
	}
}