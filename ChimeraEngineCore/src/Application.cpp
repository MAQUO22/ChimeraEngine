#include "Application.hpp"
#include <SDL3/SDL.h> 

namespace ChimeraEngineCore
{
	Application::Application(std::unique_ptr<APIContext> api_context)
		: _window(nullptr), _api_context(std::move(api_context)) {}

	int Application::start()
	{
		_api_context->initializeAPI(_window.get());

		_window = _api_context->createWindow("ChimeraEngineEditor", 1280, 720);

		while (_window->getStatus()) 
		{
			_window->pollEvents();
		}

		SDL_DestroyWindow(static_cast<SDL_Window*>(_window->getSDLWindow()));
		SDL_Quit();

		return 0;
	}
}

