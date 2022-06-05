


#pragma once


#include <controller_component.hpp>
#include <transform.hpp>

namespace MKatapulta
{
	class Bullet_Controller : public Controller_Component
	{
	protected:

		Transform* parent;
		float altura;

		float vertical_speed;
		float horizontal_speed;
		float speedx;
		float speedy;
		float speedz;
		float gravity;
		float elastic;

		bool ready;

	public:

		Bullet_Controller(Transform* parent, float altura);
		
		void Disparar(glm::vec3 pos, float angle);

		void start() {}
		void update();

		void reset();

		bool get_ready() { return ready; }

		void swapx() { speedx *= -1; }

		void swapy() { speedy *= -elastic; }

		Transform* get_transform() { return entity->get_transform(); }
	};
}