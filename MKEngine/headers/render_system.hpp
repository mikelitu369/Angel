#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>
#include <kernel.hpp>



namespace MKengine
{
	class Render_Component;

	class Renderer_System : public System
	{

		Window* window;											

	public:

		std::vector<Render_Component*> render_components;		

		std::unique_ptr < glt::Render_Node > render_node;

		Renderer_System(Window& window, Kernel& kernel);

		void initialize();

		void run(float);

		void end() {}

		void add_render_component(Render_Component*);

		std::shared_ptr<Render_Component> create_mesh(const std::string& id, const std::string& path);

		std::shared_ptr<Render_Component> create_camera(const std::string& id);


	};

}