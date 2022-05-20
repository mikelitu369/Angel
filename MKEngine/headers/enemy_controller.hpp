

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
		float speed = 0.01f;

	public:
		
		void start() {}

		void update();

		void set_target(Transform* new_target);
	};
}