

#pragma once

#include <component.hpp>


namespace engine
{
	class Render_Component : public Component
	{
	public:

		virtual glt::Node& get_node() = 0;

	};
}
