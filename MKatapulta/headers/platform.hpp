

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>


namespace MKatapulta
{
	class Platform_Controller : public Controller_Component
	{
	protected:

		Transform* catapulta;
		glm::vec3 pos1;
		glm::vec3 pos2;
		bool ready;
		float speed;

	public:

		Platform_Controller(Transform* catapulta);

		void active();

		void start() {}
		void update();

	};
}