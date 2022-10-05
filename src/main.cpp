#include <iostream>
#include <SDL.h>

#include "maple.hpp"

int main() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        std::cout << "Initializing SDL2..." << std::endl;
    } else {
        std::cerr << "Failed to initialize SDL2. \n> Error: " << SDL_GetError() << std::endl;
    }

    // Start application
    Maple maple;

    return 0;
}