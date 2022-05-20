

#pragma once


#include <system.hpp>
#include <kernel.hpp>
#include <controller_component.hpp>
#include <vector>
#include <enemy_controller.hpp>
#include <player_controller.hpp>


namespace MKengine
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

		Enemy_Controller* create_enemy_controller();

		Player_Controller* create_player_controller();

	};
}

