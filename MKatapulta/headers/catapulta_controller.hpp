

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>


namespace MKatapulta
{
	class Catapulta_Controller : public Controller_Component
	{
	private:
		
		Transform* palo;
		float speed;
		float rotation_speed;
		float gravity_speed;

	public:

		Catapulta_Controller(Transform* palo);

		void start() {}
		void update();
	};
}