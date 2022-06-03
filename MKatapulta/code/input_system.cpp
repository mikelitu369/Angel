

#include <input_system.hpp>
#include <SDL.h>


namespace MKatapulta
{
	void Input_System::run()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{

			case SDL_KEYDOWN:

				switch (event.key.keysym.sym)
				{

				case SDLK_w:
					vertical += 1;
					break;

				case SDLK_s:
					vertical -= 1;
					break;

				case SDLK_d:
					horizontal += 1;
					break;

				case SDLK_a:
					horizontal -= 1;
					break;
				}

				break;

			case SDL_KEYUP:

				switch (event.key.keysym.sym)
				{

				case SDLK_w:
					vertical -= 1;
					break;

				case SDLK_s:
					vertical += 1;
					break;

				case SDLK_d:
					horizontal -= 1;
					break;

				case SDLK_a:
					horizontal += 1;
					break;
				}

				break;

			}
		}

		if (vertical > 1) vertical = 1;
		else if (vertical < -1) vertical = -1;

		if (horizontal > 1)horizontal = 1;
		else if (horizontal < -1)horizontal = -1;
	}
}