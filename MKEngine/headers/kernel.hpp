

#pragma once

#include <set>

#include "window.hpp"
#include "task.hpp"

#include <iostream>


namespace MKengine
{
	class Render;

	class Kernel
	{

	public:

		std::set<Task*, Task::Compare> tasks;   

		bool running = true;

		Kernel();


		void initialization();


		void execute();


		void end();


		void stop_kernel();

	
		void add_task(Task*);

	};


}