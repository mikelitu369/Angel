

#pragma once

#include <component.hpp>
#include <Model.hpp>


namespace MKengine
{
	class Render_Component : public Component
	{
	public:

		virtual std::shared_ptr<glt::Node> get_node() = 0;

	};
}
