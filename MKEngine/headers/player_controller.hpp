

#pragma once

#include <controller_component.hpp>

namespace MKengine
{
	class Player_Controller : public Controller_Component
	{
	private:

		float speed = 0.02f;
		float vertical_limit = 2.5f;
		float horizontal_limit = 5;

	public:

		void start() {}
		void update();

	};
}