#include "maple.hpp"

Maple::Maple() {
    // Window
    _window = new Window("temp title", 800, 600);

    // Main loop
    while (!_window->isClosed()) {
        _input_handler.pollEvents(_window);
        _window->setText(_input_handler.getEvent());
        _window->clear();
        _window->render();
    }
}

Maple::~Maple() {}
