


#pragma once

#include <controller_component.hpp>
#include <bullet.hpp>

namespace MKatapulta
{
	class Pared_Controller : public Controller_Component
	{
	protected:

		Bullet_Controller* bullet;
		bool touched;

	public:

		Pared_Controller(Bullet_Controller* bullet);

		bool get_touched() { return touched; }
		Bullet_Controller* get_bullet() { return bullet; }

		void start() {}
		void update();
	};
}