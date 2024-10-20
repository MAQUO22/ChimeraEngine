#pragma once

#include <memory>
#include "APIContext.hpp"
#include "Window.hpp"

namespace ChimeraEngineCore
{
	class Application
	{
	public:
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator= (const Application&) = delete;
		Application& operator= (const Application&&) = delete;
		Application() = delete;

		Application(std::unique_ptr<APIContext> api_context);
		~Application() = default;

		int start();


	private:
		std::unique_ptr<Window> _window;
		std::unique_ptr<APIContext> _api_context;
	};
};



