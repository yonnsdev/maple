#ifndef MAPLE_HPP
#define MAPLE_HPP

#include <iostream>
#include <SDL.h>

#include "core/window.hpp"
#include "core/handler/input_handler.hpp"
#include "core/handler/settings_handler.hpp"

class Maple {
  public:
    Maple();
    ~Maple();

  private:
    Window *_window = nullptr;
    InputHandler &input_handler = InputHandler::instantiate();
    SettingsHandler &settings = SettingsHandler::instantiate();
};

#endif