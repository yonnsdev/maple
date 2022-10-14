#ifndef SETTINGS_HANDLER_HPP
#define SETTINGS_HANDLER_HPP

class SettingsHandler {
  public:
    SettingsHandler(const SettingsHandler &) = delete;
    static SettingsHandler &instantiate() {
        static SettingsHandler _instance;
        return _instance;
    }

    void load();

  private:
    SettingsHandler() {}
};

#endif