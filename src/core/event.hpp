#ifndef CORE_EVENT_HPP
#define CORE_EVENT_HPP

#include <SDL.h>

class EventHandler {
public:
    EventHandler(const EventHandler &) = delete;
    static EventHandler &instantiate() {
        static EventHandler _instance;
        return _instance;
    }

    void poll_events() {
        SDL_PollEvent(&_event);
    }

    SDL_Event &get_events() {
        return _event;
    }

private:
    EventHandler() {}

    SDL_Event _event;
};

#endif