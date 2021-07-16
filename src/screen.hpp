#include <iostream>
#include <vector>

/*
    On Windows check Multiple monitors and independent screens!
    On ubuntu/debian (Linux with x11 based distros) check XRandR (X R and R)
*/

#include <objc/runtime.h>
#include <CoreGraphics/CoreGraphics.h>
#include <QuartzCore/CVDisplayLink.h>
#include <IOKit/IOKitLib.h>

typedef CGDirectDisplayID screenid_t;

struct screen {
    const screenid_t id;
    const size_t number;
    const bool main, builtin;
    size_t width, height;
    double refresh_rate;
    struct resolution_t { size_t width, height; };
    std::vector<resolution_t> resolutions;
    enum class rotation_t { deg0, deg90, deg180, deg270 } rotation;

    screen(const screenid_t& id, size_t number, bool main, bool builtin,
           size_t width, size_t height, double refresh_rate,
           std::vector<resolution_t> resolutions, rotation_t rotation)
        : id(id), number(number), main(main), builtin(builtin),
          width(width), height(height),
          refresh_rate(refresh_rate),
          resolutions(resolutions),
          rotation(rotation) {}

    screen(const screen& other)
        : id(other.id), number(other.number),
          main(other.main), builtin(other.builtin),
          width(other.width), height(other.height),
          refresh_rate(other.refresh_rate),
          resolutions(other.resolutions),
          rotation(other.rotation) {}

    screen& operator=(const screen& other) {
        *((screenid_t*)&id) = other.id;
        *((size_t*)&number) = other.number;
        *((bool*)&main) = other.main;
        *((bool*)&builtin) = other.builtin;
        width = other.width; height = other.height;
        refresh_rate = other.refresh_rate;
        resolutions = other.resolutions;
        rotation = other.rotation;
        return *this;
    }

    void capture() {
        CGDisplayCapture(id);
        CGAssociateMouseAndMouseCursorPosition(false);
    }

    void release() {
        CGDisplayRelease(id);
        CGAssociateMouseAndMouseCursorPosition(true);
    }

    static std::vector<screen> listall() {
        CGDisplayCount display_count;
        std::vector<CGDirectDisplayID> display_IDs;
        CGDisplayErr err = CGGetOnlineDisplayList(0, nullptr, &display_count);
        if(err != 0) std::cerr << "Could not get number of displays" << std::endl;
        display_IDs.resize(display_count);
        err = CGGetOnlineDisplayList(display_count, &display_IDs[0], &display_count);
        if(err != 0) std::cerr << "Could not get list of displays" << std::endl;

        std::vector<screen> screens;
        screens.reserve(display_count);
        for (auto id : display_IDs) {
            size_t number = CGDisplayUnitNumber(id);
            bool main = CGDisplayIsMain(id);
            bool builtin = CGDisplayIsBuiltin(id);
            CGDisplayModeRef current_mode = CGDisplayCopyDisplayMode(id);
            size_t width = CGDisplayModeGetPixelWidth(current_mode);
            size_t height = CGDisplayModeGetPixelHeight(current_mode);
            double refresh_rate = CGDisplayModeGetRefreshRate(current_mode);
            if ((int)refresh_rate == 0) {
                CVDisplayLinkRef link;
                CVReturn ret = CVDisplayLinkCreateWithCGDisplay(id, &link);
                const CVTime time = CVDisplayLinkGetNominalOutputVideoRefreshPeriod(link);
                if (!(time.flags & kCVTimeIsIndefinite))
                    refresh_rate = (int)(time.timeScale / (double) time.timeValue);
                CVDisplayLinkRelease(link);
            }
            CFArrayRef modes = CGDisplayCopyAllDisplayModes(id, nullptr);
            int mode_count = CFArrayGetCount(modes);
            std::vector<screen::resolution_t> resolutions;
            resolutions.reserve(mode_count);
            for (size_t i = 0; i < mode_count; i++) {
                CGDisplayModeRef mode = (CGDisplayModeRef)CFArrayGetValueAtIndex(modes, i);
                if (!CGDisplayModeIsUsableForDesktopGUI(mode))
                    continue;
                resolutions.push_back({CGDisplayModeGetPixelWidth(mode),
                                    CGDisplayModeGetPixelHeight(mode)});
            }
            CFRelease(modes);
            int rotation_degrees = CGDisplayRotation(id);
            screen::rotation_t rotation;
            if (rotation_degrees == 0) rotation = screen::rotation_t::deg0;
            else if (rotation_degrees == 90) rotation = screen::rotation_t::deg90;
            else if (rotation_degrees == 180) rotation = screen::rotation_t::deg180;
            else if (rotation_degrees == 270) rotation = screen::rotation_t::deg270;
            else std::cerr << "Unknown rotation" << std::endl;
            screens.push_back(screen{id, number, main, builtin, width, height,
                                    refresh_rate, resolutions, rotation});
            CGDisplayModeRelease(current_mode);
        }

        return screens;
    }
};
