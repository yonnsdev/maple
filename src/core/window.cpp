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

void Window::clear() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    SDL_RenderClear(_renderer);
}

void Window::render() {
    drawText();
    SDL_RenderPresent(_renderer);
}

// Temp text render
void Window::drawText() {
    TTF_Font *font = TTF_OpenFont("/Library/Fonts/SF-Mono-Regular.otf", 13);
    if (font == NULL) {
        std::cerr << TTF_GetError() << std::endl;
        setClosed(1);
    }

    SDL_Color font_color = {255, 255, 255};
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, "Hello world", font_color);

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

    SDL_Rect text_rect;  //create a rect
    text_rect.x = 0;     //controls the rect's x coordinate
    text_rect.y = 0;     // controls the rect's y coordinte
    text_rect.w = 300;   // controls the width of the rect
    text_rect.h = 200;

    SDL_RenderCopy(_renderer, text_texture, NULL, &text_rect);

    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
}