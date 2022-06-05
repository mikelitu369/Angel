

#pragma once

#include <system.hpp>


namespace MKatapulta
{
	class Input_System : public System
	{
		int horizontal = 0;
		int vertical = 0;
		bool action = false;

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
		bool get_action() { if (action) { action = false; return true; } return false; }

	};
}