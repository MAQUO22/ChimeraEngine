#include <SDL3/SDL.h>

#include "DirectXContext.hpp"

namespace ChimeraEngineCore
{
	struct DirectXContext::_Impl
	{
		std::unique_ptr<Window> window = nullptr;
	};

	DirectXContext::DirectXContext()
		: _impl(std::make_unique<_Impl>()) {}

	std::unique_ptr<Window> DirectXContext::createWindow(const std::string& title, const int width, const int height)
	{
		_impl->window = std::make_unique<Window>(title, width, height);
		_impl->window->setSDLWindow(SDL_CreateWindow((title + "/DirectX").c_str(), width, height, SDL_WINDOW_RESIZABLE));
		if (!_impl->window) {
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create SDL window: %s", SDL_GetError());
		}
		return std::move(_impl->window);
	}

	void DirectXContext::initializeAPI(void* window)
	{
		std::cout << "Initializing OpenGL with SDL Window" << std::endl;

		if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
	}

	void DirectXContext::render()
	{
		std::cout << "Rendering OpenGL frame" << std::endl;
	}
}