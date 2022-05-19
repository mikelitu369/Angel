

#include <memory>
#include <vector>
#include <window.hpp>
#include <scene.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <mesh_component.hpp>
#include <render_system.hpp>
#include <kernel.hpp>


#undef main

using namespace MKengine;


int main()
{
	int width = 800;
	int height = 800;


	Window ventana("prueba", width, height);

	Scene escena("default scene", ventana);

	Entity entidad(&escena);

	Vector3 movimiento(1, 1, 1);

	entidad.get_transform()->print_position();

	entidad.get_transform()->translate(movimiento);

	entidad.get_transform()->print_position();

	Renderer_System render_system(ventana);

	//Mesh_Component cube("../models/cobe.obj", render_system);

	//entidad.add_component(&cube);

	Kernel* kernel = new Kernel();

	kernel->add_task(&render_system);

	kernel->initialization();

	kernel->execute();

	

	while (true) {}

	return 0;
}
