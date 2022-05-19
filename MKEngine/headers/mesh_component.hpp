#pragma once

#include <Model.hpp>
#include <Model_Obj.hpp>
#include <render_system.hpp>
#include <render_component.hpp>

namespace MKengine
{
	class Mesh_Component : public Render_Component
	{

		std::shared_ptr< glt::Model > model = nullptr;

	public:


		Mesh_Component(const std::string& path);

		
		std::shared_ptr<glt::Node> get_node() override
		{
			return model;
		}
	};
}

