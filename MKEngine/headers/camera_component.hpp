

#pragma once

#include <component.hpp>
#include <Camera.hpp>
#include <render_system.hpp>
#include <render_component.hpp>


namespace MKengine
{
	class Camera_Component : public Render_Component
	{


	public:

		std::shared_ptr< glt::Camera > camera = nullptr; 			


		Camera_Component();


		std::shared_ptr<glt::Node> get_node() override
		{
			return camera;
		}
	};
}