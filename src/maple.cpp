#include "maple.hpp"

Maple::Maple() {
    // Window
    _window = new Window("temp title", 800, 600);

    // Main loop
    while (!_window->isClosed()) {
        pollEvents();
    }
}

Maple::~Maple() {}

// (temp) -> Create event manager later
void Maple::pollEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _window->setClosed(true);
                SDL_Quit();
                break;
        }
    }
}