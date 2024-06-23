#include "includes.hpp"

struct opcode {    
    std::string pattern;
    std::string on;
    std::string module = "";

    std::string off;
    uintptr_t address;
};

struct hack {
    std::string name;
    std::string desc;
    std::vector<opcode> opcodes; 
    bool enabled = false;
};

struct window {
    std::string name;
    float x, y;
    float w, h;
    std::vector<hack> hacks;

    float orig_x, orig_y;
    float orig_w, orig_h;
};

namespace hacks {
    static const auto folderPath = geode::Mod::get()->getSaveDir();
    static const auto folderMacroPath = folderPath / "Macros";
    static const auto fileDataPath = folderPath / "config.json";

    extern std::vector<window> windows;
    void init();

    extern bool auto_pickup_coins;
    extern bool unlock_items;
    extern bool ignore_esc;
    extern bool startpos_switcher;
    extern bool startpos_switcher_reset_camera;
    extern bool use_a_s_d;
    extern bool instant_complate;

    extern bool rgb_icons;
    extern float ricon_coef;
    extern float ricon_shift;
    extern float ricon_saturation;
    extern float ricon_brightness;
    extern float ricon_delta;
    
    extern float speed_value;
    extern bool speedhack_audio;

    extern bool hide_menu;

    void save(const std::vector<window>& windows, const std::filesystem::path &filename);
    void load(const std::filesystem::path &filename, std::vector<window>& windows);
}