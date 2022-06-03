#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>
#include <kernel.hpp>
#include <vector>



namespace MKatapulta
{
	class Render_Component;

	class Renderer_System : public System
	{

		Window* window;											

	public:

		std::vector<Render_Component*> render_components;		

		std::unique_ptr < glt::Render_Node > render_node;

		Renderer_System(Window& window, Kernel& kernel, int priority);

		void initialize();

		void run();

		void end() {}

		void add_render_component(Render_Component*);

		Render_Component* create_mesh(const std::string& id, const std::string& path);

		Render_Component* create_camera(const std::string& id);

		Render_Component* create_light(const std::string& id);



	};

}