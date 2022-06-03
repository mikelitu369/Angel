
#pragma once

#include <component.hpp>
#include <Light.hpp>
#include <render_system.hpp>
#include <render_component.hpp>


namespace MKatapulta
{

	class Light_Component : public Render_Component
	{

		~Light_Component() = default;

	public:

		std::shared_ptr< glt::Light > light = nullptr;			

		
		Light_Component();


		std::shared_ptr<glt::Node> get_node() override
		{
			return light;
		}
	};
}
