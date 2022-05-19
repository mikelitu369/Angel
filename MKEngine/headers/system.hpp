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

		void initialize() {}
		void run(float time) {}
		void end() {}
	};
}