
#include <controller_system.hpp>


namespace MKatapulta
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

	Suelo_Controller* Controller_System::create_suelo(Transform* ref)
	{

		Suelo_Controller* component = new Suelo_Controller(ref);
		this->add_controller_component(component);

		return component;
	}

	Catapulta_Controller* Controller_System::create_catapulta_controller(Transform* liebre, Transform* palo)
	{

		Catapulta_Controller* component = new Catapulta_Controller(liebre, palo);
		this->add_controller_component(component);

		return component;
	}
}