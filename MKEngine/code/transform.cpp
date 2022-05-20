

#include <transform.hpp>
#include <entity.hpp>
#include <iostream>

namespace MKengine
{

	Transform::Transform(Transform* const newParent)
	{
		set_parent(newParent);

		position.x = 0;
		position.y = 0;
		position.z = 0;

		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;

		scale.x = 1;
		scale.y = 1;
		scale.z = 1;

		std::cout << "Se crea un entity: " << position.x << rotation.x << scale.x << " // X -> (P)osition(R)otation(S)cale" << std::endl;
	}

	Transform::Transform(glm::vec3 const position, glm::vec3 const rotation, glm::vec3 const scale, Transform* const newParent)
	{

		set_parent(newParent);

		this->position = position;

		this->rotation = rotation;

		this->scale = scale;
	}
	
	void Transform::set_parent(Transform* const newParent)
	{
		parent = newParent;
	}

	glm::mat4 Transform::get_transform_matrix() const
	{
		glm::mat4 matrix(1);

		matrix = glm::translate(matrix, position);
		matrix = glm::rotate(matrix, rotation.x, glm::vec3(1, 0, 0));
		matrix = glm::rotate(matrix, rotation.y, glm::vec3(0, 1, 0));
		matrix = glm::rotate(matrix, rotation.z, glm::vec3(0, 0, 1));
		matrix = glm::scale(matrix, scale);

		if (parent)
		{
			return parent->get_transform_matrix() * matrix;
		}

		return matrix;
	}

	glm::vec3 Transform::Position() const
	{
		if (parent) return parent->Position() + position;
		return position;
	}

	glm::vec3 Transform::Rotation() const
	{
		if (parent) return parent->Rotation() + rotation;
		return rotation;
	}

	glm::vec3 Transform::Scale() const
	{
		if (parent) return parent->Scale() + scale;
		return scale;
	}

	glm::vec3 Transform::localPosition() const
	{
		return position;
	}

	glm::vec3 Transform::localRotation() const
	{
		return rotation;
	}

	glm::vec3 Transform::localScale() const
	{
		return scale;
	}

	void Transform::set_local_position(glm::vec3 position)
	{
		this->position = position;
	}

	void Transform::translate(glm::vec3 translation)
	{
		this->position.x += translation.x;
		this->position.y += translation.y;
		this->position.z += translation.z;
	}

	void Transform::set_local_rotatoin(glm::vec3 rotation)
	{
		this->rotation = rotation;
	}

	void Transform::set_local_scale(glm::vec3 scale)
	{
		this->scale = scale;
	}
}
