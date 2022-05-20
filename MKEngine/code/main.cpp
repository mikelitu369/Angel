

#include <memory>
#include <vector>
#include <window.hpp>
#include <default_scene.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <mesh_component.hpp>
#include <render_system.hpp>
#include <kernel.hpp>
#include <scene_manager.hpp>
#include <camera_component.hpp>


#undef main

using namespace MKengine;


int main()
{
	int width = 1920;
	int height = 1080;

	//	Limites de cooredenadas de la escena X[-5, 5] Y[-2.5, 2.5]	


	Window ventana("prueba", width, height);

	Default_Scene escena("default", ventana);

	Scene_manager::instance().run_scene(&escena);

	

	while (true) {}

	return 0;
}
