
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

	template< typename T >
	T* Controller_System::create_controller()
	{

		Controller_Component* component = new T();
		this->add_controller_component(component);

		return component;
	}

}