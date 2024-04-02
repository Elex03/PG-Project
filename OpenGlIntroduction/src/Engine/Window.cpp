#include "Window.h"
#include <assert.h>
#include <SDL/SDL.h>
namespace GL
{
	Window::Window(const char* nombre, uint32_t width, uint32_t height)
	{
		assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "The window could not be initialized SDL");
		m_WindowHandle = SDL_CreateWindow("OpenGl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		assert(m_WindowHandle && "The windows doesn't exist");
	}

	Window::~Window()
	{
		SDL_DestroyWindow((SDL_Window*)m_WindowHandle);
		SDL_Quit();
	}

	void Window::GetEnvents()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				m_Runner = false;
				break;
			}
		}
	}
}