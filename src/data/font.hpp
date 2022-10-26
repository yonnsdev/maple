#ifndef CORE_TEXT_HPP
#define CORE_TEXT_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

#include "../element/textbox.hpp"

#define NULL_PATH ""

enum FontType {
    REGULAR = 00,
    BOLD = 01,
    ITALIC = 10,
};

struct Font {
    std::string regular = NULL_PATH;
    std::string italic = NULL_PATH;
    std::string bold = NULL_PATH;
    std::string bold_italic = NULL_PATH;
};

class ProgramFont {
public:
    ProgramFont(const ProgramFont &) = delete;
    static ProgramFont &instantiate() {
        static ProgramFont _instance;
        return _instance;
    }

    void set_font(Font font) {
        if (font.regular != NULL_PATH || font.italic != NULL_PATH || font.bold != NULL_PATH ||
            font.bold_italic != NULL_PATH) {
            if (_font != nullptr) {
                _font = new Font();
            }

            _font->regular = font.regular;
            _font->italic = font.italic;
            _font->bold = font.bold;
            _font->bold_italic = font.bold_italic;
        } else {
            std::cerr << "core/font.hpp : Font is not valid" << std::endl;
        }
    }

    void create_textbox() {}

private:
    ProgramFont() {}

    Font *_font = nullptr;
};

#endif