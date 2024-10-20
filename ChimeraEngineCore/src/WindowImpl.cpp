#include "WindowImpl.hpp"

namespace ChimeraEngineCore
{
	WindowImpl::WindowImpl(const std::string& title, int width, int height)
		: _title(title), _width(width), _height(height), _event{} {}

	WindowImpl::~WindowImpl()
	{
		if (_window)
		{
			SDL_DestroyWindow(_window);
			_window = nullptr;
		}
	}

	SDL_Window* WindowImpl::getSDLWindow() const
	{
		return _window;
	}

	void WindowImpl::setSDLWindow(void* window_prt)
	{
		_window = static_cast<SDL_Window*>(window_prt);
	}

	void WindowImpl::pollEvents()
	{
		while (_is_running)
		{
			while (SDL_PollEvent(&_event))
			{
				switch (_event.type)
				{
				case SDL_EVENT_QUIT:
					shouldClose();
					break;
				}
			}
		}
	}

	bool WindowImpl::getStatus() const
	{
		return _is_running;
	}

	void WindowImpl::shouldClose()
	{
		_is_running = false;
	}

}


