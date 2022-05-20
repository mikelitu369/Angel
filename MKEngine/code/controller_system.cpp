
#include <controller_system.hpp>


namespace MKengine
{
	Controller_System::Controller_System(Kernel& kernel, int priority)
	{
		this->priority = priority;
		kernel.add_task(this);
	}

	void Controller_System::initialize()
	{
		for (auto& component : controller_components)
		{
			if (component)
			{
				component->start();
			}
		}
	}

	void Controller_System::run()
	{
		for (auto& component : controller_components)
		{
			if (component)
			{
				component->update();
			}
		}
	}

	void Controller_System::add_controller_component(Controller_Component* new_component)
	{
		controller_components.push_back(new_component);
	}

	Enemy_Controller* Controller_System::create_enemy_controller()
	{

		Enemy_Controller* component = new Enemy_Controller();
		this->add_controller_component(component);

		return component;
	}

	Player_Controller* Controller_System::create_player_controller()
	{

		Player_Controller* component = new Player_Controller();
		this->add_controller_component(component);

		return component;
	}
}