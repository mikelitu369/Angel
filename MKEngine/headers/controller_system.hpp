

#pragma once


#include <system.hpp>
#include <kernel.hpp>
#include <controller_component.hpp>
#include <vector>



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

		template< typename T >
		T* create_controller();
	};
}

