#pragma once

#include <iostream>

namespace MKengine
{
	class Task
	{

	public:

		int priority;			

		struct Compare
		{			
			bool operator () (const Task* a, const Task* b) const
			{
				return  a->priority < b->priority;
			}
		};


		Task(int priority = 0)
		{
			this->priority = priority;
		}

		virtual void run(float time) = 0;
		virtual void initialize() = 0;
		virtual void end() = 0;


		bool operator < (const Task& other) const
		{
			return this->priority < other.priority;
		}

		virtual ~Task() = default;

	};

}