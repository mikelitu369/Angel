


#pragma once

#include <iostream>
#include <Window.hpp>
#include <cassert>
#include <OpenGL.hpp>
#include <SDL.h>


namespace MKengine
{
	Window::Window(const std::string& title, size_t width, size_t height)
	{
		gl_context = nullptr;

		this->width = width;
		this->height = height;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("Error SDL2.");
		}
		else
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, int(width), int(height), SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}

		if (not window)
		{
			SDL_Log("Error window.");
		}
		else
		{
			gl_context = SDL_GL_CreateContext(window);

			assert(gl_context != nullptr);			
		}
	}

	void Window::end()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}



	void Window::clear() const
	{
		if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(window);
	}

	unsigned Window::get_width()
	{
		recalculate_width_and_height();

		return unsigned(this->width);
	}

	unsigned Window::get_height()
	{
		recalculate_width_and_height();

		return unsigned(this->height);
	}

	void Window::recalculate_width_and_height()
	{
		int width = 0, height = 0;

		if (window)
		{
			SDL_GetWindowSize(window, &width, &height);
			this->width = (unsigned)width;
			this->height = (unsigned)height;
		}

	}
}
