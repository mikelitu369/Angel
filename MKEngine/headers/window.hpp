

#pragma once

#include <ciso646>
#include <SDL.h>
#include <iostream>


namespace MKengine
{
	class Window
	{
	private:

		size_t width = 0;
		size_t height = 0;

		SDL_Window* window = nullptr;
		SDL_GLContext gl_context;

		void recalculate_width_and_height();

	public:

		Window(const std::string& title, size_t  width, size_t height);

		void end();

		void clear() const;
		void swap_buffers() const;

		unsigned get_width();
		unsigned get_height();
	};
}