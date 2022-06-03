

#pragma once


#include <system.hpp>
#include <kernel.hpp>
#include <controller_component.hpp>
#include <vector>
#include<suelo.hpp> 
#include<catapulta_controller.hpp>


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
		Catapulta_Controller* create_catapulta_controller(Transform* liebre, Transform* palo);

	};
}

