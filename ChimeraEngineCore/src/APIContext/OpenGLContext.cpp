#include <SDL3/SDL.h>

#include "OpenGLContext.hpp"

namespace ChimeraEngineCore
{
	struct OpenGLContext::_Impl
	{
		std::unique_ptr<Window> window = nullptr;
	};

	OpenGLContext::OpenGLContext()
		: _impl(std::make_unique<_Impl>()) {}

	std::unique_ptr<Window> OpenGLContext::createWindow(const std::string& title, const int width, const int height)
	{
		_impl->window = std::make_unique<Window>(title, width, height);
		_impl->window->setSDLWindow(SDL_CreateWindow((title + "/OpenGL").c_str(), width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE));
		if (!_impl->window) {
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create SDL window: %s", SDL_GetError());
		}
		return std::move(_impl->window);
	}
	void OpenGLContext::initializeAPI(void* window)
	{
		std::cout << "Initializing OpenGL with SDL Window" << std::endl;

		if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
	}

	void OpenGLContext::render()
	{
		std::cout << "Rendering OpenGL frame" << std::endl;
	}
}

