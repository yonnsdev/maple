#include "window.hpp"

Window::Window(const std::string title, int w, int h) : _w(w), _h(h), _title(title) {
    if (!init()) {
        _closed = true;
    }
}

Window::~Window() {
    std::cout << "Closing window..." << std::endl;

    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

bool Window::init() {
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _w,
                               _h, SDL_WINDOW_RESIZABLE);
    if (_window != nullptr) {
        std::cout << "Created window(" << _w << ", " << _h << ")..." << std::endl;
    } else {
        std::cerr << "Failed to create window.\n> Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer != nullptr) {
        std::cout << "Created renderer..." << std::endl;
    } else {
        std::cerr << "Failed to create renderer.\n>Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}