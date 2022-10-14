#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "maple.hpp"

int main() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        std::cout << "Initializing SDL2..." << std::endl;
    } else {
        std::cerr << "Failed to initialize SDL2.\n> Error: " << SDL_GetError() << std::endl;
    }

    if (TTF_Init() == 0) {
        std::cout << "Initializing SDL2_TTF..." << std::endl;
    } else {
        std::cerr << "Failed to initialize SDL2_TTF.\n> Error: " << TTF_GetError() << std::endl;
    }

    // Start application
    Maple maple;

    return 0;
}