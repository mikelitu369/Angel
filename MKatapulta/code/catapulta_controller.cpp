
#include <catapulta_controller.hpp>
#include <input_system.hpp>
#include <scene_manager.hpp>


namespace MKatapulta
{

	Catapulta_Controller::Catapulta_Controller(Transform* palo)
	{
		this->palo = palo;

		speed = 0.05;
		rotation_speed = 0.01;
		gravity_speed = 0.1;
	}

	void Catapulta_Controller::update()
	{
		Transform* transform = this->get_entity()->get_transform();		

		glm::vec3 rotation = transform->localRotation();
		rotation.y += Input_System::instance().get_horizontal() * -rotation_speed;
		transform->set_local_rotatoin(rotation);

		glm::vec3 position = transform->localPosition();
		float angulo = transform->localRotation().y;
		glm::vec3 direction(sin(angulo),0,cos(angulo));
		position += direction * -speed * (float)Input_System::instance().get_vertical();
		position.y -= gravity_speed;
		transform->set_local_position(position);

		if (transform->localPosition().y < -10) Scene_manager::instance().reset();
	}
}