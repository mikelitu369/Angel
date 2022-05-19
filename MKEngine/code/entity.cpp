

#include <entity.hpp>
#include <transform.hpp>
#include <scene.hpp>

namespace MKengine
{
	Entity::Entity(Scene* scene)
	{
		id = "";

		this->transform = new Transform();
		add_component(transform);

		scene->add_entity(this);
	}

	Entity::Entity(std::string& id, Scene* scene)
	{
		this->id = id;

		this->transform = new Transform();
		add_component(transform);

		scene->add_entity(this);
	}

	Entity::Entity(std::string& id, Scene* scene, Transform* parent)
	{
		this->id = id;

		this->transform = new Transform(parent);
		add_component(transform);

		scene->add_entity(this);
	}

	
	void Entity::add_component(Component* new_component)
	{
		new_component->set_entity(this);
		components.push_back(new_component);
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

	void Entity::set_active(bool state)
	{
		this->active = state;
	}

}
