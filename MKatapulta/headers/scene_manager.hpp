

#pragma once

#include <map>
#include <vector>



#include <iostream>
#include <map>

namespace MKatapulta
{
	class Scene;

	typedef std::string Id;

	class Scene_manager
	{
	private:

		std::map<std::string, Scene*> scenes_map; 				
		std::vector <Scene*> scenes_vector;
		Scene* current_scene;						

	public:

		static Scene_manager& instance()			
		{
			static Scene_manager scene_manager;
			return scene_manager;
		}


		void add_scene(Scene* newscene);

		void run_scene(Scene* scene);
		void run_scene(std::string scene_name);
		void run_scene(unsigned scene_id);

		Scene* get_current_scene() const;

		void close();

		void reset();
	};

}