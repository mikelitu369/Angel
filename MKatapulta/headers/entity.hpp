
#pragma once



#include <vector>
#include <iostream>
#include <component.hpp>


namespace MKatapulta
{
	class Transform;
	class Scene;


	class Entity
	{
	private:

		std::string id;							

		std::vector<Component*> components;		

		Transform* transform = nullptr;		

		bool active;



	public:

		Entity(Scene* scene);
		Entity(Scene* scene, Transform* parent);
		Entity(std::string& id, Scene* scene);
		Entity(std::string& id, Scene* scene, Transform* parent);


		void add_component(Component* new_component);

		Transform* get_transform();

		template< typename T >
		T* get_component();
		
		std::string* get_id();

		void set_active(bool state);

	};
}


