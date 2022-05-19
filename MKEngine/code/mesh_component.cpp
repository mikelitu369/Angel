

#include <mesh_component.hpp>
#include <iostream>
#include <Cube.hpp>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace MKengine
{
	Mesh_Component::Mesh_Component(const std::string& path, Renderer_System& render_system)
	{

		model.reset(new Model_Obj(path));


		render_system.render_node->add(*entity->get_id(), model);
		render_system.add_render_component(this);
	}

}