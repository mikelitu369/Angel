

#include <window.hpp>
#include <default_scene.hpp>
#include <scene_manager.hpp>
#include <iostream>


#undef main

using namespace MKengine;


int main()
{
	int width = 1920;
	int height = 1080;

	//	Limites de cooredenadas de la escena X[-5, 5] Y[-2.5, 2.5]	


	Window ventana("prueba", width, height);

	std::cout << "Ventana creada exitosamente:   " << width << " / " << height << "   width / height" << std::endl;

	Default_Scene escena("default", ventana);
	
	std::cout << "Escena creada:  " << &escena << " / " << &ventana << "   direccion_memoria_escena / direccion_memoria_ventana" << std::endl;

	std::cout << "Comienza ejecucion en kernel..." << std::endl;

	Scene_manager::instance().run_scene(&escena);

	std::cout << "Fin de ejecucion" << std::endl;

	return 0;
}
