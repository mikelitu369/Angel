


#include <enemy_controller.hpp>
#include <glm/glm.hpp>
#include <entity.hpp>



namespace MKengine
{

	void Enemy_Controller::set_target(Transform* new_target)
	{
		target = new_target;
	}

	void Enemy_Controller::update()
	{
		glm::vec3 vector_director = target->Position() - entity->get_transform()->Position();

		float factor_reductor = 10;
		vector_director.x /= factor_reductor;
		vector_director.y /= factor_reductor;
		vector_director.z /= factor_reductor;

		entity->get_transform()->translate(vector_director);
	}
}