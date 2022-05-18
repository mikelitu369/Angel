

#include <iostream>
#include <map>
#include <memory>


#include "entity.hpp"
//#include "scene_manager.hpp"
//#include <render_component.hpp>
//#include <control_system.hpp>
//#include <collision_system.hpp>

#pragma once

namespace engine
{
	class Window;

	typedef std::string Id;

	class Scene
	{
	private:

		std::map<Id, Entity* > entities;

		//->std::unique_ptr <Renderer_System>	 renderer_system;		
		//->std::unique_ptr <Control_System>	 control_system;		
		//->std::unique_ptr <Collision_System>	 collision_system;		
		//->std::unique_ptr <Physics2d_System>   physics2d_system;

		std::string name;									
		std::string path;		

	public:


		Scene(const std::string& name, const std::string& path, Window& window);

	
		void init();


		void update(float time);


		void render();


		void add_entity(Entity*);


		Entity* get_entity(const std::string&);


		std::string get_name()
		{
			return name;
		}

	};


}
