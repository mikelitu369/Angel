

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>
#include <bullet.hpp>

namespace MKatapulta
{
	class Suelo_Controller : public Controller_Component
	{
	private:

		Transform* catapulta;
		Bullet_Controller* bullet;

	public:

		Suelo_Controller(Transform* ref, Bullet_Controller* bullet) { catapulta = ref; this->bullet = bullet; };

		void set_catapulta(Transform* catapulta) { this->catapulta = catapulta; }

		void start() {}
		void update();
	};
}