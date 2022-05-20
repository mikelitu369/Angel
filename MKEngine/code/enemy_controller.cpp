


#include <enemy_controller.hpp>
#include <glm/glm.hpp>
#include <entity.hpp>
#include <scene_manager.hpp>




namespace MKengine
{

	void Enemy_Controller::set_target(Transform* new_target)
	{
		target = new_target;
	}

	void Enemy_Controller::update()
	{
		glm::vec3 vector_director = target->Position() - entity->get_transform()->Position();
		
		float magnitude = glm::length(vector_director);

		if (magnitude <= 0.75)
		{
			Scene_manager::instance().reset();
		}

		vector_director = glm::normalize(vector_director) * speed;

		entity->get_transform()->translate(vector_director);


	}
}