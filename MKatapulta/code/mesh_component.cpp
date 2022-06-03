

#include <mesh_component.hpp>
#include <iostream>
#include <Cube.hpp>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace MKatapulta
{
	Mesh_Component::Mesh_Component(const std::string& path)
	{
		model.reset(new Model_Obj(path));		
	}

}