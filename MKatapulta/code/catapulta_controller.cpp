
#include <catapulta_controller.hpp>
#include <input_system.hpp>
#include <scene_manager.hpp>


namespace MKatapulta
{

	Catapulta_Controller::Catapulta_Controller(Transform* palo, Bullet_Controller* bullet)
	{
		this->palo = palo;
		this->bullet = bullet;

		speed = 0.05;
		rotation_speed = 0.01;
		gravity_speed = 0.1;
		rotation = 0;
		disparo = false;
		disparo_speed = 0.3f;
		retroceso = false;
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

		if (Input_System::instance().get_action() && bullet->get_ready()) disparo = true;
		if (disparo)
		{
			if (!retroceso)
			{
				if (this->rotation < 3.14 / 2)
				{
					glm::vec3 palo_rot = palo->localRotation();
					palo_rot.x -= disparo_speed;
					palo->set_local_rotatoin(palo_rot);
					this->rotation += disparo_speed;
				}
				else
				{
					bullet->Disparar(position, angulo);
					retroceso = true;
				}
			}
			else
			{
				if (this->rotation > 0)
				{
					glm::vec3 palo_rot = palo->localRotation();
					palo_rot.x += 0.01;
					palo->set_local_rotatoin(palo_rot);
					this->rotation -= 0.01;
				}
				else
				{
					retroceso = false;
					disparo = false;
				}
			}
		}
	}
}