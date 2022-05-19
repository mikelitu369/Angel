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

		virtual void initialize() = 0;
		virtual void run(float time) = 0;
		virtual void end() = 0;
	};
}