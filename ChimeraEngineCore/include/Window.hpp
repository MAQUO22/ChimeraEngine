#pragma once

#include <string>
#include <memory>

namespace ChimeraEngineCore
{
    class WindowImpl;

    class Window
    {
    public:
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        Window(const std::string& title, int width, int height);
        ~Window();

        Window(Window&& other) noexcept;
        Window& operator=(Window&& other) noexcept;

        void* getSDLWindow() const;
        void setSDLWindow(void* window_prt);
        void pollEvents();
        bool getStatus() const;
        void shouldClose();

    private:
        std::unique_ptr<WindowImpl> _impl;
    };
}