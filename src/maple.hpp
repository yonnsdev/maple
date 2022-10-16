#ifndef MAPLE_HPP
#define MAPLE_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Maple {
public:
    Maple(const Maple &) = delete;

    static Maple &instantiate() {
        static Maple _instance;
        return _instance;
    }

    void start() {
        initiate_sdl();

        // starting code here
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
};

#endif