


#include <puerta_controller.hpp>


namespace MKatapulta
{
	Puerta_Controller::Puerta_Controller(Transform* muro1, Transform* muro2)
	{
		this->muro1 = muro1;
		this->muro2 = muro2;
		open = false;
		position = 0;
		door_size = 8;
		speed = 0.01f;
	}

	void Puerta_Controller::active()
	{
		open = true;
	}

	void Puerta_Controller::update()
	{
		if (!open) return;
		if (position < door_size / 2)
		{
			glm::vec3 position1 = muro1->localPosition();
			position1.z += speed;
			muro1->set_local_position(position1);

			glm::vec3 position2 = muro2->localPosition();
			position2.z -= speed;
			muro2->set_local_position(position2);

			position += speed;
		}
	}
}