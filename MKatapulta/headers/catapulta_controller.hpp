

#pragma once

#include <controller_component.hpp>
#include <transform.hpp>
#include <bullet.hpp>


namespace MKatapulta
{
	class Catapulta_Controller : public Controller_Component
	{
	private:
		
		Transform* palo;
		float speed;
		float rotation_speed;
		float gravity_speed;
		bool disparo;
		float rotation;
		float disparo_speed;
		bool retroceso;
		Bullet_Controller* bullet;
		

	public:

		Catapulta_Controller(Transform* palo, Bullet_Controller* bullet);

		void start() {}
		void update();
	};
}