#pragma once

#include <task.hpp>
#include <vector>
#include <component.hpp>
#include <scene.hpp>

namespace MKengine
{
	class System : public Task
	{

	public:

		Scene* scene;							

		std::vector<Component*> components;		


		void initialize() {}
		void run(float time);
		void end() {}


		void add_component(Component*);
	};
}