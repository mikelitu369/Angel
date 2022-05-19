#pragma once

#include <Model.hpp>
#include <Model_Obj.hpp>
#include <render_system.hpp>
#include <render_component.hpp>

namespace MKengine
{
	class Mesh_Component : public Render_Component
	{


	public:

		std::shared_ptr< glt::Model > model = nullptr;

		Mesh_Component(const std::string& path, Renderer_System& render_system);

		
		glt::Node& get_node() override
		{
			return *model;
		}
	};
}

