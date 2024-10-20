#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace ChimeraEngineCore
{
    class WindowImpl {
    public:
        WindowImpl(const std::string& title, int width, int height);
        ~WindowImpl();

        SDL_Window* getSDLWindow() const;
        void setSDLWindow(void* window_prt);
        void pollEvents();
        bool getStatus() const;
        void shouldClose();

    private:
        SDL_Window* _window = nullptr;
        SDL_Event _event;
        bool _is_running = true;

        std::string _title;
        int _width;
        int _height;
    };
}