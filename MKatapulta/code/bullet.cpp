


#include <bullet.hpp>

namespace MKatapulta
{
	Bullet_Controller::Bullet_Controller(Transform* parent, float altura)
	{
		this->parent = parent;
		this->altura = altura;

		vertical_speed=0.2;
		horizontal_speed=-0.2;
		speedx=0;
		speedy=0;
		speedz=0;
		gravity=vertical_speed/50;
		elastic = 0.5;

		ready = true;
	}

	void Bullet_Controller::Disparar(glm::vec3 pos, float angle)
	{
		speedx = horizontal_speed * sin(angle);
		speedy = vertical_speed;
		speedz = horizontal_speed * cos(angle);

		Transform* transform = entity->get_transform();
		transform->set_parent(nullptr);
		transform->set_local_position(pos + glm::vec3(0, altura, 0));

		ready = false;
	}

	void Bullet_Controller::reset()
	{
		Transform* transform = entity->get_transform();
		transform->set_parent(parent);
		transform->set_local_position(glm::vec3(0, altura, 0));

		ready = true;;
	}

	void Bullet_Controller::update()
	{
		if (ready) return;

		Transform* transform = entity->get_transform();
		if (transform->localPosition().y < -50)
		{
			reset();
			return;
		}

		glm::vec3 position = transform->localPosition();
		position.x += speedx;
		position.z += speedz;
		speedy -= gravity;
		position.y += speedy;
		transform->set_local_position(position);
	}
}