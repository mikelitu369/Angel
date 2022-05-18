

#include <scene.hpp>
#include <sstream>


using namespace std;

namespace MKengine
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
	

	void Scene::add_entity(Entity* new_entity)
	{
		assert_entity_id(new_entity->get_id());
		entities.insert(std::pair<std::string, Entity*>(*new_entity->get_id(), new_entity));
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

	void Scene::assert_entity_id(std::string* id) 
	{
		if (entities[*id] != nullptr) 
		{
			unsigned iterator = 0;
			std::string base;
			do
			{
				++iterator;
				base = *id + std::to_string(iterator);
			
			} while (entities[base] != nullptr);

			*id = base;
		}
	}
}
