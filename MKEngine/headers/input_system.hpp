

#pragma once

#include <system.hpp>


namespace MKengine
{
	class Input_System : public System
	{
		int horizontal = 0;
		int vertical = 0;

	public:

		static Input_System& instance()
		{
			static Input_System input_system;
			return input_system;
		}

		void initialize() {}

		void run();

		void end() {}

		int get_horizontal() { return horizontal; }
		int get_vertical() { return vertical; }

	};
}