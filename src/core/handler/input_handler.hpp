#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SDL.h>

#include "../window.hpp"

class InputHandler {
  public:
    InputHandler(const InputHandler &) = delete;
    static InputHandler &instantiate() {
        static InputHandler _instance;
        return _instance;
    }

    void pollEvents(Window *window);

    inline SDL_Event &getEvent() {
        return _event;
    }

  private:
    InputHandler() {}

    void keyboardEvents();

    SDL_Event _event;
};

#endif
