

#pragma once

#include <set>

#include "window.hpp"
#include "task.hpp"

#include <iostream>


namespace MKatapulta
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