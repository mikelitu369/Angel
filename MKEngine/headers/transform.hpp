

#pragma once

#include <component.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <entity.hpp>

namespace MKengine
{
	typedef glm::mat4 Matrix44;
	typedef glm::vec3 Vector3;

	class Transform : public Component
	{
	private:

		Vector3 position;			
		Vector3 rotation;			
		Vector3 scale;				

		Transform* parent = nullptr;			


	public:

		Transform(Transform* const newParent = nullptr);
		Transform(Vector3 const position, Vector3 const rotation, Vector3 const scale, Transform* const newParent = nullptr);


		void set_parent(Transform* const newParent);

		
		Matrix44 get_transform_matrix() const;

		Vector3 Position() const;
		Vector3 Rotation() const;
		Vector3 Scale() const;

		Vector3 localPosition() const;
		Vector3 localRotation() const;
		Vector3 localScale() const;

		void set_local_position(Vector3 position);
		void translate(Vector3 translation);
		void set_local_rotatoin(Vector3 rotation);
		void set_local_scale(Vector3 scale);

		void print_position()
		{
			std::cout << "Posicion de "  << *entity->get_id() << ": " << Position().x << Position().y << Position().z << std::endl;
		}
	};
}
