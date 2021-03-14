#ifndef LIBTEXTSCREEN_ENTITY_HPP
#define LIBTEXTSCREEN_ENTITY_HPP

#include <screen/screen.hpp>
#include <std/stdcxx.hpp>

namespace system::io::entity
{
    class TextScreen : public Screen
    {
    public:
        TextScreen();

        uint32_t row;
        uint32_t column;
        static const uint32_t MAX_BUFFER_SIZE = 4096;
        char buffer[MAX_BUFFER_SIZE];

        void drawChar(uint32_t x, uint32_t y, system::media::entity::Color color, char ch);

        TextScreen *print(const char *content);
        TextScreen *print(int64_t content);
        TextScreen *print(uint64_t content);

        void fresh();
    private:
        uint32_t bufferCount = 0;
    };

} // namespace system::io::entity

#endif