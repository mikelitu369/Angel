


#pragma once


#include <scene.hpp>
#include <vector>
#include <glm/glm.hpp>



namespace MKatapulta
{

	class Default_Scene : public Scene
	{
	private:
		
		std::vector<glm::vec3> posiciones_originales;
		std::vector<Entity*> entidades_reset;

	public:
		
		Default_Scene(const std::string& name, Window& window);

		void setup() override;

		void reset() override;

	};
}