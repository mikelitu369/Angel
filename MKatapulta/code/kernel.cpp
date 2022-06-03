

#include <kernel.hpp>
#include <thread>


namespace MKatapulta
{
	Kernel::Kernel()
	{
		running = true;
	}

	void Kernel::initialization()
	{
		for (auto task : tasks)
		{
			task->initialize();
		}
	}

	void Kernel::execute()
	{
		while (running)
		{
			for (Task* task : tasks)
			{
				task->run();
			}			
		} 


		end();
	}

	void Kernel::end()
	{
		for (auto task : tasks)
		{
			task->end();
		}
	}

	void Kernel::add_task(Task* new_task)
	{
		tasks.insert(new_task);
	}

	void Kernel::stop_kernel()
	{
		running = false;
	}

}