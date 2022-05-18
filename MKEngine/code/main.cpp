

#include <memory>
#include <vector>
#include <window.hpp>
#include <scene.hpp>
#include <entity.hpp>


#undef main

using namespace MKengine;


int main()
{
	int width = 800;
	int height = 800;


	Window ventana = Window("prueba", width, height);

	Scene escena = Scene("default scene", ventana);

	for (size_t i = 0; i < 10; i++)
	{
		Entity entidad = Entity(&escena);
	}

	while (true) {}

	return 0;
}
