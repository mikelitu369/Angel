

#include <player_controller.hpp>
#include <input_system.hpp>
#include <glm/glm.hpp>
#include<entity.hpp>
#include<transform.hpp>

#include <iostream>



namespace MKengine
{

	void Player_Controller::update()
	{
		glm::vec3 vector_director(0, 0, 0);

		vector_director.x += Input_System::instance().get_horizontal();
		vector_director.y += Input_System::instance().get_vertical();
		vector_director *= speed;

		entity->get_transform()->translate(vector_director);

		glm::vec3 actual_position = entity->get_transform()->Position();

		if (actual_position.x > horizontal_limit) actual_position.x = horizontal_limit;
		else if (actual_position.x < -horizontal_limit) actual_position.x = -horizontal_limit;

		if (actual_position.y > vertical_limit) actual_position.y = vertical_limit;
		else if (actual_position.y < -vertical_limit) actual_position.y = -vertical_limit;

		entity->get_transform()->set_local_position(actual_position);
	}
}