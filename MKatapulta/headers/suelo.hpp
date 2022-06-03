

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>

namespace MKatapulta
{
	class Suelo_Controller : public Controller_Component
	{
	private:

		Transform* catapulta;

	public:

		Suelo_Controller(Transform* ref) { catapulta = ref; };

		void set_catapulta(Transform* catapulta) { this->catapulta = catapulta; }

		void start() {}
		void update();
	};
}