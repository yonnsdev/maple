#ifndef DATA_SETTINGS_HPP
#define DATA_SETTINGS_HPP

/*
    Reads and sets settings
*/

#include <fstream>
#include <iostream>
#include <string>

class Settings {
public:
    Settings(const Settings &) = delete;
    static Settings &instantiate() {
        static Settings _instance;
        return _instance;
    }

private:
    Settings() {}

    // Temp path for debugging.
    std::string _temp_path = "/Users/yonns/Developer/maple/res/settings/settings.json";
};

#endif