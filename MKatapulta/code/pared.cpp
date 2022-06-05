


#include <pared.hpp>


namespace MKatapulta
{
	Pared_Controller::Pared_Controller(Bullet_Controller* bullet)
	{
		this->bullet = bullet;
		touched = false;
	}

	void Pared_Controller::update()
	{
		Transform* transform = entity->get_transform();
		Transform* transform_bullet = bullet->get_transform();

		if (transform_bullet->Position().x > transform->Position().x - transform->Scale().x / 2 &&
			transform_bullet->Position().x < transform->Position().x + transform->Scale().x / 2 &&
			transform_bullet->Position().z > transform->Position().z - transform->Scale().z / 2 &&
			transform_bullet->Position().z < transform->Position().z + transform->Scale().z / 2 &&
			transform_bullet->Position().y < transform->Position().y + transform->Scale().y &&
			transform_bullet->Position().y > transform->Position().y)
		{
			touched = true;
			bullet->swapx();
		}
	}
}