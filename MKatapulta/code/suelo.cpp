


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

	}
}
