#include <SDL3/SDL.h>

#include "VulkanContext.hpp"

namespace ChimeraEngineCore
{
	struct VulkanContext::_Impl
	{
		std::unique_ptr<Window> window = nullptr;
	};

	VulkanContext::VulkanContext() :
		_impl(std::make_unique<_Impl>()) {}

	std::unique_ptr<Window> VulkanContext::createWindow(const std::string& title, const int width, const int height)
	{
		_impl->window = std::make_unique<Window>(title, width, height);
		_impl->window->setSDLWindow(SDL_CreateWindow((title + "/Vulkan").c_str(), width, height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE));
		if (!_impl->window) {
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create SDL window: %s", SDL_GetError());
		}
		return std::move(_impl->window);
	}

	void VulkanContext::initializeAPI(void* window)
	{
		std::cout << "Initializing Vulkan API with SDL Window" << std::endl;

		if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
			SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());

	}

	void VulkanContext::render()
	{
		std::cout << "Rendering Vulkan frame" << std::endl;
	}
}