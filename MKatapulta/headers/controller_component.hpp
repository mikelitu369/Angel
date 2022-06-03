

#pragma once

#include <component.hpp>


namespace MKatapulta
{
	class Controller_Component : public Component
	{
	public:

		virtual void start() = 0;
		virtual void update() = 0;
		
	};
}