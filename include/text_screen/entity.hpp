#pragma once

#include <color/color.hpp>
#include <font/font.hpp>
#include <screen/screen.hpp>
#include <std/stdcxx.hpp>

namespace system::io::entity {

class TextScreen : public Screen {
public:
    TextScreen();
    TextScreen(system::media::entity::Font  defaultFont,
               system::media::entity::Color defaultColor);

    static const uint32_t MAX_BUFFER_SIZE = 4096;

    TextScreen *drawChar(const uint32_t &x, const uint32_t &y,
                         const char &ch);

    TextScreen *drawChar(const uint32_t &x, const uint32_t &y,
                         const char &                        ch,
                         const system::media::entity::Font & font,
                         const system::media::entity::Color &color);

    TextScreen *print(const char *content);
    TextScreen *print(int64_t content);
    TextScreen *print(uint64_t content);

    void fresh();

private:
    char     buffer[MAX_BUFFER_SIZE];
    uint32_t bufferCount;
    uint32_t row;
    uint32_t column;

    system::media::entity::Font  defaultFont;
    system::media::entity::Color defaultColor;
}; // class TextScreen

} // namespace system::io::entity
