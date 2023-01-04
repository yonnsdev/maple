#ifndef EDITOR_EDITOR_HPP
#define EDITOR_EDITOR_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

#include "../core/event.hpp"
#include "../core/pane.hpp"
#include "../core/window.hpp"

class Editor : protected Pane {
public:
    Editor(int x, int y, int w, int h) : Pane{x, y, w, h} {}

    void update() {
        get_key();
    }

    void get_key() {
        SDL_Keycode key = _event_handler.get_events().key.keysym.sym;
        if (key == 127) {
            _code.pop_back();
        } else if (key >= 32 && key <= 126) {
            char ch = key;
            _code.push_back(key);
        }
    }

private:
    Window &_window = Window::instantiate();
    SDL_Renderer *_renderer = _window.get_renderer();
    EventHandler &_event_handler = EventHandler::instantiate();

    std::string _code = "";
};

#endif