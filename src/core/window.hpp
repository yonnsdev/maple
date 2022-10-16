#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <SDL.h>
#include <iostream>

class Window {
public:
    Window(const Window &) = delete;

    static Window &instantiate() {
        static Window _instance;
        return _instance;
    }

private:
    Window() {}
};

#endif