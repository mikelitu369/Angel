

#include <key.hpp>


namespace MKatapulta
{
	Key_Controller::Key_Controller(Transform* catapulta, Platform_Controller* platform, Puerta_Controller* puerta, Transform* cubo)
	{
		this->catapulta = catapulta;
		this->platform = platform;
		this->puerta = puerta;
		this->cubo = cubo;

		rotation_speed = 0.01f;
	    vertical_speed = 0.01f;
		speed = vertical_speed;
		upper_limit = 1;
		lower_limit = 0;

		radio = 1;
		recogida = false;
	}

	void Key_Controller::Recoger()
	{
		recogida = true;
		cubo->set_local_scale(glm::vec3(0.01, 0.01, 0.01));
		platform->active();
		puerta->active();
	}

	void Key_Controller::update()
	{
		if (recogida) return;

		glm::vec3 rotation = cubo->localRotation();
		rotation.y += rotation_speed;
		cubo->set_local_rotatoin(rotation);


		if (cubo->localPosition().y > upper_limit) speed = -vertical_speed;
		if (cubo->localPosition().y < lower_limit) speed = vertical_speed;
		cubo->translate(glm::vec3(0, speed, 0));

		glm::vec3 position = entity->get_transform()->localPosition();

		if (abs(catapulta->localPosition().x - position.x) < radio ||
			abs(catapulta->localPosition().z - position.z) < radio)
		{
			Recoger();
		}
	}
}