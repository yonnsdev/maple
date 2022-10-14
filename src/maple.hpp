#ifndef MAPLE_HPP
#define MAPLE_HPP

#include <SDL.h>
#include <iostream>

#include "core/handler/input_handler.hpp"
#include "core/handler/settings_handler.hpp"
#include "core/window.hpp"

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