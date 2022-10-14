#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

class Window {
  public:
    Window(std::string title, int w, int h);
    ~Window();

    void clear();
    void render();

    // TEMP: text rendering
    void setText(SDL_Event &event);
    void drawText();

    inline bool isClosed() const {
        return _closed;
    }
    inline void setClosed(bool val) {
        _closed = val;
    }

  private:
    bool init();

  private:
    int _w, _h;
    const std::string _title;

    bool _closed = false;

    int _text_w, _text_h;
    std::string _temp_text;

    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
};

#endif