#pragma once

#include <task.hpp>

namespace MKengine
{
	class System : public Task
	{

	public:

		virtual void initialize() = 0;
		virtual void run() = 0;
		virtual void end() = 0;
	};
}