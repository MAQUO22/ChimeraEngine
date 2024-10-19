#include "test.hpp"

int main(int argc, char* argv[]) {

    if(!SDL_InitSubSystem(SDL_INIT_VIDEO))
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

    int w = 800;
    int h = 600;

    auto window = SDL_CreateWindow("asdasd", w, h, SDL_WINDOW_RESIZABLE);

    if(!window)
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 75, 255, 12);

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_QuitSubSystem(SDL_INIT_VIDEO);

    return 0;
}
