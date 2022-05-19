

#pragma once

namespace MKengine
{
	class Entity;

	class Component
	{
	protected:

		Entity* entity = nullptr;

	public:

		virtual ~Component() = default;

		void set_entity(Entity* const reference)
		{
			this->entity = reference;
		};

		Entity* get_entity() const { return entity; }
	};

}
