#include "input_handler.hpp"

#include <iostream>

void InputHandler::pollEvents(Window *window) {
    if (SDL_PollEvent(&_event)) {
        switch (_event.type) {
            case SDL_QUIT:
                window->setClosed(1);
                SDL_Quit();
                break;
            default:
                break;
        }
    }
}

void InputHandler::keyboardEvents() {
    if (_event.type == SDL_KEYDOWN) {
        switch (_event.key.keysym.sym) {}
    }
}