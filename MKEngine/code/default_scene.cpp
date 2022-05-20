

#include <default_scene.hpp>
#include <vector>
#include <transform.hpp>
#include <enemy_controller.hpp>

namespace MKengine
{
	Default_Scene::Default_Scene(const std::string& name, Window& window) : Scene(name, window) {}

	void Default_Scene::setup()
	{
		Entity* camera = new Entity(this);
		glm::vec3 posicion_camara(0, 0, 5);
		camera->get_transform()->set_local_position(posicion_camara);
		camera->add_component(renderer_system->create_camera("main_camera"));

		Entity* luz = new Entity(this);
		glm::vec3 posicion_luz(10, 10, 10);
		luz->get_transform()->set_local_position(posicion_luz);
		luz->add_component(renderer_system->create_light("luz"));

		Entity* player = new Entity(this);
		glm::vec3 posicion_player(0, 0, 0);
		glm::vec3 escala_player(0.5f, 0.5f, 0.5f);
		player->get_transform()->set_local_scale(escala_player);
		player->add_component(renderer_system->create_mesh("player", "../models/sphere.obj"));
		player->add_component(controller_system->create_player_controller());
		entidades_reset.push_back(player);
		posiciones_originales.push_back(posicion_player);

		{
			Entity* enemy = new Entity(this);
			glm::vec3 posicion_enemy(5, 2.5f, 0);
			enemy->get_transform()->set_local_position(posicion_enemy);
			enemy->add_component(renderer_system->create_mesh("enemy", "../models/sphere.obj"));
			Enemy_Controller* controller_component = controller_system->create_enemy_controller();
			enemy->add_component(controller_component);
			controller_component->set_target(player->get_transform());
			entidades_reset.push_back(enemy);
			posiciones_originales.push_back(posicion_enemy);
		}

		{
			Entity* enemy = new Entity(this);
			glm::vec3 posicion_enemy(5, -2.5f, 0);
			enemy->get_transform()->set_local_position(posicion_enemy);
			enemy->add_component(renderer_system->create_mesh("enemy1", "../models/sphere.obj"));
			Enemy_Controller* controller_component = controller_system->create_enemy_controller();
			enemy->add_component(controller_component);
			controller_component->set_target(player->get_transform());
			entidades_reset.push_back(enemy);
			posiciones_originales.push_back(posicion_enemy);
		}

		{
			Entity* enemy = new Entity(this);
			glm::vec3 posicion_enemy(-5, -2.5f, 0);
			enemy->get_transform()->set_local_position(posicion_enemy);
			enemy->add_component(renderer_system->create_mesh("enemy2", "../models/sphere.obj"));
			Enemy_Controller* controller_component = controller_system->create_enemy_controller();
			enemy->add_component(controller_component);
			controller_component->set_target(player->get_transform());
			entidades_reset.push_back(enemy);
			posiciones_originales.push_back(posicion_enemy);
		}

		{
			Entity* enemy = new Entity(this);
			glm::vec3 posicion_enemy(-5, 2.5f, 0);
			enemy->get_transform()->set_local_position(posicion_enemy);
			enemy->add_component(renderer_system->create_mesh("enemy3", "../models/sphere.obj"));
			Enemy_Controller* controller_component = controller_system->create_enemy_controller();
			enemy->add_component(controller_component);
			controller_component->set_target(player->get_transform());
			entidades_reset.push_back(enemy);
			posiciones_originales.push_back(posicion_enemy);
		}

	}
	void Default_Scene::reset()
	{
		for (size_t i = 0; i < entidades_reset.size(); i++)
		{
			entidades_reset[i]->get_transform()->set_local_position(posiciones_originales[i]);
		}
	}
}