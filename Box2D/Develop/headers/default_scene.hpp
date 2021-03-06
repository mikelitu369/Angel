


#pragma once


#include <vector>
#include <object.hpp>
#include <render.hpp>
#include <car.hpp>


namespace MKbox2D
{
	class SceneDefault
	{
	private:

		RenderWindow* window;

		std::vector<Object*> objectos;

		b2World* world;

		Render* render_system;

		void Proces();

		void Update();

		bool active = true;

		Car* car;

	public:


		SceneDefault();

		void Run();

		void Add_object(Object* new_object);

	};
}