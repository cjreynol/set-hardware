#include "Card.h"

namespace Set
{
    Card::Card()
        : color(0b11)
        , number(0b11)
        , shape(0b11)
        , fill(0b11)
    {
    }

    Card::Card(uint8_t color, uint8_t number, uint8_t shape, uint8_t fill)
        : color(color)
        , number(number)
        , shape(shape)
        , fill(fill)
    {
    }
}// namespace
