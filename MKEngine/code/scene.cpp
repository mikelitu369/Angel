

#include <scene.hpp>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

namespace engine
{
	Scene::Scene(const std::string& name, const std::string& path, Window& window)
	{
		this->name = name;
		this->path = path;


		//->Scene_manager::instance().add_scene(this);

		//->renderer_system.reset(new Renderer_System(window));
		//->control_system.reset(new Control_System);
		//->collision_system.reset(new Collision_System);
	}

	void Scene::init()
	{
		ifstream file(path);
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());

	}	

	void Scene::add_entity(Entity* new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}

	Entity* Scene::get_entity(const std::string& id)
	{

		return entities[id];

	}


	void Scene::update(float time)
	{
		//->control_system->run(time);
		//->collision_system->run(time);
	}

	void Scene::render()
	{
		//->renderer_system->run(0);
	}

}
