

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>
#include <platform.hpp>
#include <puerta_controller.hpp>

namespace MKatapulta
{
	class Key_Controller : public Controller_Component
	{
	protected:

		Transform* catapulta;
		Platform_Controller* platform;
		Puerta_Controller* puerta;
		Transform* cubo;

		float rotation_speed;
		float vertical_speed;
		float speed;
		float upper_limit;
		float lower_limit;

		float radio;
		bool recogida;

	public:

		Key_Controller(Transform* catapulta, Platform_Controller* platform, Puerta_Controller* puerta, Transform* cubo);

		void Recoger();

		virtual void start() {}
		void update();

	};
}