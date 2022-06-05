

#include <platform.hpp>

#include <iostream>

namespace MKatapulta
{
	Platform_Controller::Platform_Controller(Transform* catapulta)
	{
		this->catapulta = catapulta;
		pos1 = glm::vec3(2, -1, -10);
		pos2 = glm::vec3(33, -1, -10);
		this->ready = false;
		speed = 0.05f;
	}

	void Platform_Controller::active()
	{
		ready = true;
	}

	void Platform_Controller::update()
	{
		if (!ready) return;

		Transform* transform = this->get_entity()->get_transform();

		if (transform->localPosition().y < pos1.y)
		{
			transform->translate(glm::vec3(0, speed/2, 0));
		}

		bool in =
			transform->localPosition().x + transform->localScale().x / 2 > catapulta->localPosition().x &&
			transform->localPosition().x - transform->localScale().x / 2 < catapulta->localPosition().x &&
			transform->localPosition().z + transform->localScale().z / 2 > catapulta->localPosition().z &&
			transform->localPosition().z - transform->localScale().z / 2 < catapulta->localPosition().z;
		

		glm::vec3 translation(speed, 0, 0);

		if (in)
		{
			if (transform->localPosition().x < pos2.x)
			{
				transform->translate(translation);
				catapulta->translate(translation);
			}
		}
		else
		{
			if (transform->localPosition().x > pos1.x)
			{
				transform->translate(-translation);
			}
		}
	}
}