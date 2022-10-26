#ifndef DATA_DATA_HPP
#define DATA_DATA_HPP

/*
    Stores and manages data (settings, file, temp_saves, etc)
*/

#include <iostream>

#include "font.hpp"

class Data {
public:
    Data(const Data &) = delete;
    static Data &instantiate() {
        static Data _instance;
        return _instance;
    }

private:
    Data() {
        // VERY TEMPORARY
        _temp_font.regular = "/Users/yonns/Developer/maple/res/fonts/JetBrainsMono-Regular.ttf";
        _temp_font.italic = "/Users/yonns/Developer/maple/res/fonts/JetBrainsMono-Italic.ttf";
        _temp_font.bold = "/Users/yonns/Developer/maple/res/fonts/JetBrainsMono-Bold.ttf";
        _temp_font.bold_italic =
            "/Users/yonns/Developer/maple/res/fonts/JetBrainsMono-BoldItalic.ttf";
        _font.set_font(_temp_font);
    }

    // VERY TEMPORARY
    ProgramFont &_font = ProgramFont::instantiate();
    Font _temp_font;
};

#endif