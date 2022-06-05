

#pragma once

#include <controller_component.hpp>
#include <pared.hpp>


namespace MKatapulta
{
	class Bloque_Controller : public Controller_Component
	{
	protected:

		Pared_Controller* ref;
		float rotation_speed;
		float speed_ref;
		float vertical_speed;
		float altura;
		float gravity;
		bool falling;

	public:

		Bloque_Controller(Pared_Controller* pared);

		void start() {}
		void update();

	};
}