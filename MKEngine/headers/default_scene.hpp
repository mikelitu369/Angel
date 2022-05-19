


#pragma once


#include <scene.hpp>


namespace MKengine
{

	class Default_Scene : public Scene
	{
	public:
		
		Default_Scene(const std::string& name, Window& window);

		void setup() override;

	};
}