

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>


namespace MKatapulta
{
	class Puerta_Controller : public Controller_Component
	{
	protected:

		Transform* muro1;
		Transform* muro2;
		bool open;
		float position;
		float door_size;
		float speed;

	public:

		Puerta_Controller(Transform* muro1, Transform* muro2);

		void active();

		void start() {}
		void update();

	};
}