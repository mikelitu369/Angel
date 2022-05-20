
#include <light_component.hpp>
#include <iostream>
#include <entity.hpp>
#include <transform.hpp>


using namespace glt;
using namespace std;

namespace MKengine
{
	Light_Component::Light_Component()
	{
		light.reset(new Light);
	}
}