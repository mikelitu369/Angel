


#include <suelo.hpp>


namespace MKatapulta
{
	void Suelo_Controller::update()
	{
		if (catapulta == nullptr) return;


		Transform* transform = entity->get_transform();

		if(	catapulta->Position().x > transform->Position().x - transform->Scale().x / 2 &&
			catapulta->Position().x < transform->Position().x + transform->Scale().x / 2 &&
			catapulta->Position().z > transform->Position().z - transform->Scale().z / 2 &&
			catapulta->Position().z < transform->Position().z + transform->Scale().z / 2 &&
			catapulta->Position().y < transform->Position().y + transform->Scale().y &&
			catapulta->Position().y > transform->Position().y)
		{
			glm::vec3 new_position(catapulta->Position().x, transform->Position().y + transform->Scale().y, catapulta->Position().z);
			catapulta->set_local_position(new_position);
		}

		Transform* transform_bullet = bullet->get_transform();

		if (transform_bullet->Position().x > transform->Position().x - transform->Scale().x / 2 &&
			transform_bullet->Position().x < transform->Position().x + transform->Scale().x / 2 &&
			transform_bullet->Position().z > transform->Position().z - transform->Scale().z / 2 &&
			transform_bullet->Position().z < transform->Position().z + transform->Scale().z / 2 &&
			transform_bullet->Position().y < transform->Position().y + transform->Scale().y &&
			transform_bullet->Position().y > transform->Position().y)
		{
			glm::vec3 new_position(transform_bullet->Position().x, transform->Position().y + 0.1 + transform->Scale().y, transform_bullet->Position().z);
			transform_bullet->set_local_position(new_position);
			bullet->swapy();
		}

	}
}
