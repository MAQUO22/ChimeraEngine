#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "Window.hpp"

namespace ChimeraEngineCore
{
	class APIContext
	{
	public:
		virtual ~APIContext() = default;

		virtual std::unique_ptr<Window> createWindow(const std::string& title, const int width, const int height) = 0;
		virtual void initializeAPI(void* window) = 0;
		virtual void render() = 0;
	};
}