#pragma once

#include <color/color.hpp>
#include <font/font.hpp>
#include <screen/screen.hpp>
#include <std/stdcxx.hpp>

namespace system::io::entity {

class TextScreen : public Screen {
public:
    TextScreen(system::media::entity::Color defaultColor,
               system::media::entity::Font  defaultFont);

    static const uint32_t MAX_BUFFER_SIZE = 4096;

    TextScreen *drawChar(const uint32_t &x, const uint32_t &y,
                         const uint8_t &ch);

    TextScreen *drawChar(const uint32_t &x, const uint32_t &y,
                         const uint8_t &                     ch,
                         const system::media::entity::Color &color,
                         const system::media::entity::Font & font);

    TextScreen *print(const uint8_t *content);
    TextScreen *print(int64_t content);
    TextScreen *print(uint64_t content);

    void fresh();

private:
    char     buffer[MAX_BUFFER_SIZE];
    uint32_t bufferCount;
    uint32_t row;
    uint32_t column;

    system::media::entity::Color defaultColor;
    system::media::entity::Font  defaultFont;
}; // class TextScreen

} // namespace system::io::entity
