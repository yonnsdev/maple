#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <SDL.h>
#include <iostream>
#include <string>

class Window {
public:
    Window(const Window &) = delete;
    static Window &instantiate() {
        static Window _instance;
        return _instance;
    }

    bool create(std::string title, int w, int h) {
        if (_window == nullptr && _renderer == nullptr) {
            std::cout << "Creating window..." << std::endl;
            _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_RESIZABLE);
            if (_window == nullptr) {
                std::cerr << "Failed to create window.\n> Error: " << SDL_GetError() << std::endl;
                return false;
            }

            std::cout << "Creating renderer..." << std::endl;
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
            if (_renderer == nullptr) {
                std::cerr << "Failed to create renderer.\n> Error: " << SDL_GetError() << std::endl;
                return false;
            }

            return true;
        }

        std::cerr << "Window is already created." << std::endl;
        return false;
    }

    void present() {
        SDL_RenderPresent(_renderer);
    }

    void clear() {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
        SDL_RenderClear(_renderer);
    }

    void quit() {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
    }

private:
    Window() {}

    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
};

#endif