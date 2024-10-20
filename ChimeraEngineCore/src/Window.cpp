#include "Window.hpp"
#include "WindowImpl.hpp"
#include <stdexcept>

namespace ChimeraEngineCore
{
	Window::Window(const std::string& title, int width, int height)
		: _impl(std::make_unique<WindowImpl>(title, width, height)) {}

	Window::~Window() = default;

	Window::Window(Window&& other) noexcept
		: _impl(std::move(other._impl)) {}

	Window& Window::operator=(Window&& other) noexcept
	{
		if (this != &other)
			_impl = std::move(other._impl);

		return *this;
	}
	void* Window::getSDLWindow() const
	{
		return _impl->getSDLWindow();
	}

	void Window::setSDLWindow(void* window_prt)
	{
		_impl->setSDLWindow(window_prt);
	}

	void Window::pollEvents()
	{
		_impl->pollEvents();
	}

	bool  Window::getStatus() const
	{
		return _impl->getStatus();
	}

	void  Window::shouldClose()
	{
		_impl->shouldClose();
	}
}