#ifndef MAPLE_HPP
#define MAPLE_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "core/event.hpp"
#include "core/window.hpp"

class Maple {
public:
    Maple(const Maple &) = delete;
    static Maple &instantiate() {
        static Maple _instance;
        return _instance;
    }

    void run() {
        initiate_sdl();

        if (!_window.create("Maple", 800, 600)) {
            _is_running = false;
        }

        while (_is_running) {
            _event_handler.poll_events();
            check_events();

            _window.clear();
            _window.present();
        }

        quit();
    }

private:
    Maple() {}

    void initiate_sdl() {
        // SDL2
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            std::cout << "Initiating SDL2..." << std::endl;
        } else {
            std::cerr << "Failed to initiate SDL2.\n> Error: " << SDL_GetError() << std::endl;
        }

        // SDL2_TTF
        if (TTF_Init() == 0) {
            std::cout << "Initiating SDL2_TTF..." << std::endl;
        } else {
            std::cerr << "Failed to initiate SDL2_TTF.\n> Error: " << TTF_GetError() << std::endl;
        }
    }

    void check_events() {
        switch (_event_handler.get_events().type) {
            case SDL_QUIT:
                _is_running = false;
                break;
            default:
                break;
        }
    }

    void quit() {
        _window.quit();

        TTF_Quit();
        SDL_Quit();
    }

private:
    Window &_window = Window::instantiate();
    EventHandler &_event_handler = EventHandler::instantiate();

    bool _is_running = true;
};

#endif