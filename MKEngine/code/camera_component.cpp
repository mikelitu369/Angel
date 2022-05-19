



#include <camera_component.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <iostream>

using namespace glt;
using namespace std;

namespace MKengine
{

	Camera_Component::Camera_Component(const std::string & id)
	{

		camera.reset(new Camera(20.f, 1.f, 50.f, 1.f));

	}


}