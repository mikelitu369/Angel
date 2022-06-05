

#pragma once


#include <system.hpp>
#include <kernel.hpp>
#include <controller_component.hpp>
#include <vector>
#include <suelo.hpp> 
#include <catapulta_controller.hpp>
#include <puerta_controller.hpp>
#include <platform.hpp>
#include <key.hpp>


namespace MKatapulta
{

	class Controller_System : public System
	{
	public:

		std::vector<Controller_Component*> controller_components;

		Controller_System(Kernel& kernel, int priority);

		void initialize();

		void run();

		void end() {}


		void add_controller_component(Controller_Component* component);

		Suelo_Controller* create_suelo(Transform* ref);
		Catapulta_Controller* create_catapulta_controller(Transform* palo);
		Puerta_Controller* create_puerta(Transform* muro1, Transform* muro2);
		Platform_Controller* create_platform(Transform* catapulta);
		Key_Controller* create_key(Transform* catapulta, Platform_Controller* platform, Puerta_Controller* puerta, Transform* cubo);
	};
}

