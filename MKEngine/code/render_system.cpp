#pragma once

#include <render_system.hpp>
#include <render_component.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <scene.hpp>
#include <mesh_component.hpp>
#include <camera_component.hpp>

using namespace glt;

namespace MKengine
{
	Renderer_System::Renderer_System(Window& window, Kernel & kernel)
	{
		this->window = &window;
		render_node.reset(new Render_Node);
		kernel.add_task(this);
	}

	void Renderer_System::run(float time = 0)
	{
		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());

		render_node->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		for (auto& component : render_components)
		{
			if (component)
			{
				Matrix44 transform_matrix = component->get_entity()->get_transform()->get_transform_matrix();
				component->get_node()->set_transformation(transform_matrix);
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

	void Renderer_System::initialize()
	{

	}

	Render_Component* Renderer_System::create_mesh(const std::string& id, const std::string& path)
	{

		Render_Component* component = new Mesh_Component(path);
		this->render_node->add(id, component->get_node());
		this->add_render_component(component);

		return component;
	}

	Render_Component* Renderer_System::create_camera(const std::string& id)
	{
		Render_Component* component = new Camera_Component();
		this->render_node->add(id, component->get_node());
		this->add_render_component(component);

		return component;
	}
}