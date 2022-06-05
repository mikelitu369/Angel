
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

	Catapulta_Controller* Controller_System::create_catapulta_controller(Transform* palo)
	{

		Catapulta_Controller* component = new Catapulta_Controller(palo);
		this->add_controller_component(component);

		return component;
	}

	Puerta_Controller* Controller_System::create_puerta(Transform* muro1, Transform* muro2)
	{

		Puerta_Controller* component = new Puerta_Controller(muro1, muro2);
		this->add_controller_component(component);

		return component;
	}

	Platform_Controller* Controller_System::create_platform(Transform* catapulta)
	{

		Platform_Controller* component = new Platform_Controller(catapulta);
		this->add_controller_component(component);

		return component;
	}

	Key_Controller* Controller_System::create_key(Transform* catapulta, Platform_Controller* platform, Puerta_Controller* puerta, Transform* cubo)
	{

		Key_Controller* component = new Key_Controller(catapulta, platform, puerta, cubo);
		this->add_controller_component(component);

		return component;
	}
}