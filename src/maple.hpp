#ifndef MAPLE_HPP
#define MAPLE_HPP

#include <iostream>
#include <SDL.h>

#include "window/window.hpp"

class Maple {
  public:
    Maple();
    ~Maple();

  private:
    void pollEvents();

  private:
    Window *_window = nullptr;
};

#endif