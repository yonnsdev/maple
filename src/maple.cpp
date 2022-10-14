#include "maple.hpp"

Maple::Maple() {
    // Window
    _window = new Window("temp title", 800, 600);

    // Main loop
    while (!_window->isClosed()) {
        input_handler.pollEvents(_window);
    }
}

Maple::~Maple() {}
