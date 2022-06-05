


#include <scene.hpp>
#include <sstream>
#include <input_system.hpp>


using namespace std;

namespace MKatapulta
{
	Scene::Scene(const std::string& name,  Window& window)
	{
		this->name = name;

		kernel.reset(new Kernel());
		renderer_system.reset(new Renderer_System(window, *kernel, 2));
		controller_system.reset(new Controller_System(*kernel, 1));
		kernel->add_task(&Input_System::instance());

		Scene_manager::instance().add_scene(this);
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


	void Scene::assert_entity_id(std::string* id) 
	{
		if (entities.find(*id) != entities.end()) 
		{
			unsigned iterator = 0;
			std::string base;
			do
			{
				++iterator;
				base = *id + std::to_string(iterator);
			
			} while (entities.find(base) != entities.end());

			*id = base;
		}
	}	

	void Scene::setup()
	{

	}

	void Scene::init()
	{
		kernel->initialization();
		kernel->execute();
	}

	void Scene::load()
	{
		setup();
		init();
	}

	void Scene::close()
	{
		kernel->stop_kernel();

		for (auto& entity : entities)
		{
			entity.second = NULL;
			delete entity.second;
		}

	}
}
