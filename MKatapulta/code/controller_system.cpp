
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

	Suelo_Controller* Controller_System::create_suelo(Transform* ref, Bullet_Controller* bullet)
	{

		Suelo_Controller* component = new Suelo_Controller(ref, bullet);
		this->add_controller_component(component);

		return component;
	}

	Catapulta_Controller* Controller_System::create_catapulta_controller(Transform* palo, Bullet_Controller* bullet)
	{

		Catapulta_Controller* component = new Catapulta_Controller(palo, bullet);
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

	Bullet_Controller* Controller_System::create_bullet(Transform* parent, float altura)
	{

		Bullet_Controller* component = new Bullet_Controller(parent, altura);
		this->add_controller_component(component);

		return component;
	}

	Pared_Controller* Controller_System::create_pared(Bullet_Controller* bullet)
	{

		Pared_Controller* component = new Pared_Controller(bullet);
		this->add_controller_component(component);

		return component;
	}

	Bloque_Controller* Controller_System::create_bloque(Pared_Controller* pared)
	{

		Bloque_Controller* component = new Bloque_Controller(pared);
		this->add_controller_component(component);

		return component;
	}
}