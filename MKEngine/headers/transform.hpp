

#pragma once

#include <component.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <entity.hpp>

namespace MKengine
{

	class Transform : public Component
	{
	private:

		glm::vec3 position;			
		glm::vec3 rotation;			
		glm::vec3 scale;				

		Transform* parent = nullptr;			


	public:

		Transform(Transform* const newParent = nullptr);
		Transform(glm::vec3 const position, glm::vec3 const rotation, glm::vec3 const scale, Transform* const newParent = nullptr);


		void set_parent(Transform* const newParent);

		
		glm::mat4 get_transform_matrix() const;

		glm::vec3 Position() const;
		glm::vec3 Rotation() const;
		glm::vec3 Scale() const;

		glm::vec3 localPosition() const;
		glm::vec3 localRotation() const;
		glm::vec3 localScale() const;

		void set_local_position(glm::vec3 position);
		void translate(glm::vec3 translation);
		void set_local_rotatoin(glm::vec3 rotation);
		void set_local_scale(glm::vec3 scale);

		void print_position()
		{
			std::cout << "Posicion de "  << *entity->get_id() << ": " << Position().x << Position().y << Position().z << std::endl;
		}
	};
}
