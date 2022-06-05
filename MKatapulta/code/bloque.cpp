


#include <bloque.hpp>

namespace MKatapulta
{
	Bloque_Controller::Bloque_Controller(Pared_Controller* pared)
	{
		ref = pared;
		altura = pared->get_entity()->get_transform()->localScale().y;
		rotation_speed = 0;
		falling = false;
		vertical_speed = 0;
		gravity = 0.004;
		speed_ref = 0.03;
	}


	void Bloque_Controller::update()
	{
		if (!falling)
		{
			if (ref->get_touched())
			{
				float altura_impacto = ref->get_bullet()->get_transform()->localPosition().y;
				rotation_speed = speed_ref * (altura_impacto / altura);
				falling = true;
			}
		}
		else
		{
			Transform* transform = this->get_entity()->get_transform();

			glm::vec3 rotation = transform->localRotation();
			rotation_speed += gravity / 100;
			rotation.z -= rotation_speed;
			transform->set_local_rotatoin(rotation);

			if (rotation.z < -3.14 / 2)
			{
				vertical_speed += gravity;
				transform->translate(glm::vec3(0, -vertical_speed, 0));
			}
		}
	}

}