

#pragma once

#include <ciso646>
#include <SDL.h>
#include <iostream>


namespace MKengine
{
	class Window
	{

	public:

		size_t width = 0;
		size_t height = 0;

		SDL_Window* window = nullptr;			

		SDL_GLContext gl_context;				

		Window(const std::string& title, size_t  width, size_t height, bool fullscreen = false);

		void end();

		void handle_events();

		void clear() const;
		void swap_buffers() const;

		unsigned get_width() const;
		unsigned get_height() const;
	};
}