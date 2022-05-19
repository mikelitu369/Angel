
#pragma once

#include <iostream>
#include <map>
#include <memory>


#include "entity.hpp"
#include "scene_manager.hpp"
#include <render_component.hpp>
#include <render_system.hpp>
#include <kernel.hpp>


namespace MKengine
{
	class Window;	

	class Renderer_System;

	class Scene
	{
	protected:

		std::map<std::string, Entity* > entities;

		std::unique_ptr <Kernel> kernel;
		std::unique_ptr <Renderer_System> renderer_system;

		std::string name;									

		void assert_entity_id(std::string*);

		virtual void setup();

		void init();

	public:


		Scene(const std::string& name, Window& window);


		void add_entity(Entity* entity);


		Entity* get_entity(const std::string&);


		std::string get_name()
		{
			return name;
		}

		void load();
	};


}
