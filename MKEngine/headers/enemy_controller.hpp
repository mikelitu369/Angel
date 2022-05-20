

#pragma once

#include <controller_component.hpp>
#include <glm/glm.hpp>
#include <transform.hpp>


namespace MKengine
{
	class Enemy_Controller : public Controller_Component
	{
	private:

		Transform* target;

	public:
		
		void start() {}

		void update();

		void set_target(Transform* new_target);
	};
}