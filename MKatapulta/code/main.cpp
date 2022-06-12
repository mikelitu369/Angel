

#include <window.hpp>
#include <default_scene.hpp>
#include <scene_manager.hpp>

#undef main

using namespace MKatapulta;

int main()
{
	int width = 1920;
	int height = 1080;

	Window ventana("prueba", width, height);

	Default_Scene escena("default", ventana);
	
	Scene_manager::instance().run_scene(&escena);

	return 0;
}
