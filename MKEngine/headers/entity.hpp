
#pragma once



#include <vector>
#include <iostream>
//#include "component.hpp"


namespace MKengine
{
	class Transform;
	class Scene;


	class Entity
	{
	private:

		std::string id;							

		//->std::vector<Component*> components;		

		Transform* transform = nullptr;			


	public:

		Entity(Scene* scene);
		Entity(std::string& id, Scene* scene);
		Entity(std::string& id, Scene* scene, Transform* transform);


		//->void add_component(Component* new_component);


		void add_transform(Transform* new_component);

		Transform* get_transform();


		template< typename T >
		T* get_component();
		
		std::string* get_id();
	};
}


