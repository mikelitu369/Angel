#include <scene_manager.hpp>
#include <scene.hpp>

namespace MKengine
{

	void Scene_manager::add_scene(Scene* newscene)
	{
		scenes_vector.push_back(newscene);

		scenes_map.insert(std::pair<std::string, Scene*>(newscene->get_name(), newscene));
	}


	void Scene_manager::run_scene(Scene* scene)
	{
		current_scene = scene;

		if (scenes_map.find(scene->get_name()) == scenes_map.end())
		{
			add_scene(scene);
		}

		current_scene->load();
	}

	void Scene_manager::run_scene(std::string name_scene)
	{
		if (scenes_map.find(name_scene) != scenes_map.end())
		{
			current_scene = scenes_map[name_scene];
			run_scene(current_scene);
		}
	}

	void Scene_manager::run_scene(unsigned scene_index)
	{
		if (scenes_vector.size() > scene_index)
		{
			current_scene = scenes_vector[scene_index];
			run_scene(current_scene);
		}
	}

	Scene* Scene_manager::get_current_scene() const
	{
		return current_scene;
	}
}
