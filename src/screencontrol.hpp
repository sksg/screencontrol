#include <iostream>

#include "screen.hpp"

void list_screens() {

    auto screens = screen::listall();

    for (auto screen : screens) {
        std::cout << "Display " << screen.number << ": ";
        if (screen.main) std::cout << "main screen";
        std::cout << " " << (screen.builtin ? "(built-in)" : "(external)") << std::endl;
        std::cout << "width: " << screen.width << ", ";
        std::cout << "height: " << screen.height << std::endl;
        std::cout << "rotation: ";
        if (screen.rotation == screen::rotation_t::deg0)
            std::cout << "0 degrees" << std::endl;
        if (screen.rotation == screen::rotation_t::deg90)
            std::cout << "90 degrees" << std::endl;
        if (screen.rotation == screen::rotation_t::deg180)
            std::cout << "180 degrees" << std::endl;
        if (screen.rotation == screen::rotation_t::deg270)
            std::cout << "270 degrees" << std::endl;
        std::cout << "refresh_rate: " << screen.refresh_rate << std::endl;
        std::cout << "Other resolutions: " << std::endl;
        for (auto res : screen.resolutions) {
            std::cout << "  width: " << res.width << ", ";
            std::cout <<   "height: " << res.height << std::endl;
        }

        if (!screen.main) {
            std::cout << "disable screen... " << std::flush;
            screen.capture();
            std::cout << "done!" << std::endl;
            sleep(5);
            std::cout << "enable screen... " << std::flush;
            screen.release();
            std::cout << "done!" << std::endl;
            sleep(5);
            std::cout << "disable screen... " << std::flush;
            screen.capture();
            std::cout << "done!" << std::endl;
        }
    }
}