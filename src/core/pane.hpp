#ifndef CORE_PANE_HPP
#define CORE_PANE_HPP

#include <SDL.h>

class Pane {
public:
    Pane(int x, int y, int w, int h) : _x(x), _y(y), _width(w), _height(h) {
        _pane_rect.x = x;
        _pane_rect.y = y;
        _pane_rect.w = w;
        _pane_rect.h = h;
    };

protected:
    int _x, _y;
    int _width, _height;

    SDL_Rect _pane_rect;
};

#endif