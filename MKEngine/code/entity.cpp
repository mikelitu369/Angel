

#include <entity.hpp>
#include <transform.hpp>
#include <scene.hpp>

namespace MKengine
{
	Entity::Entity(Scene* scene)
	{
		id = "";

		/*
			Añadir aqui una inclusion de transform forzada reseteado a cero
		*/

		scene->add_entity(this);
	}

	Entity::Entity(std::string& id, Scene* scene)
	{
		this->id = id;

		/*
			Añadir aqui una inclusion de transform forzada reseteado a cero
		*/

		scene->add_entity(this);
	}

	Entity::Entity(std::string& id, Scene* scene, Transform* transform)
	{
		this->id = id;

		this->transform = transform;
		add_component(transform);

		scene->add_entity(this);
	}

	Entity::Entity(std::string& id)
	{
		this->id = id;

		this->transform = nullptr;
	}

	void Entity::add_component(Component* new_component)
	{
		components.push_back(new_component);
	}

	void Entity::add_transform(Transform* new_component)
	{
		transform = new_component;
	}

	Transform* Entity::get_transform()
	{
		return this->transform;
	}

	template< typename T >
	T* Entity::get_component()
	{
		for (auto& component : components)
		{
			auto casted_component = dynamic_cast<T*>(component);

			if (casted_component)
			{
				return casted_component;
			}
		}

		return nullptr;
	}

	std::string* Entity::get_id() 
	{
		return &id;
	}
}
