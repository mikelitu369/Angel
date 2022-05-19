#pragma once

#include <render_system.hpp>
#include <render_component.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <scene.hpp>

using namespace glt;

namespace MKengine
{
	Renderer_System::Renderer_System(Window& w)
	{
		window = &w;
		render_node.reset(new Render_Node);
	}

	void Renderer_System::run(float time = 0)
	{
		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());

		render_node->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		//Go throw the all render components
		for (auto& component : render_components)
		{
			if (component)
			{
				Matrix44 transform_matrix = component->get_entity()->get_transform()->get_transform_matrix();
				component->get_node().set_transformation(transform_matrix);
			}
		}

		window->clear();
		render_node->render();
		window->swap_buffers();
	}

	void Renderer_System::add_render_component(Render_Component* new_component)
	{
		render_components.push_back(new_component);
	}
}