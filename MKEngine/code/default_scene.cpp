

#include <default_scene.hpp>
#include <vector>
#include <transform.hpp>

namespace MKengine
{
	Default_Scene::Default_Scene(const std::string& name, Window& window) : Scene(name, window) {}

	void Default_Scene::setup()
	{
		Entity camera(this);
		glm::vec3 posicion_camara(0, -10, 0);
		camera.get_transform()->set_local_position(posicion_camara);
		camera.add_component(renderer_system->create_camera("main_camera"));

		Entity cubo(this);		
		cubo.add_component(renderer_system->create_mesh("cubo","../models/cube.obj"));
	}
}