

#pragma once

#include <component.hpp>


namespace MKengine
{
	class Controller_Component : public Component
	{
	public:


		Controller_Component();

		virtual void start() = 0;
		virtual void update() = 0;
		
	};
}