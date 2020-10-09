#pragma once

#include <stdint.h>

namespace Set
{
    class Card
    {
    public:
        /// <summary>
        /// Default all of the fields to undefined values;
        /// </summary>
        Card();

        Card(uint8_t color, uint8_t number, uint8_t shape, uint8_t fill);

        uint8_t color : 2;  // 00 - Red, 01 - Green, 10 - Purple, 11 - Undefined
        uint8_t number : 2; // 00, 01, 10 - Decimal value, 11 - Undefined
        uint8_t shape : 2;  // 00 - Rounded, 01 - Diamond, 10 - Squiggle, 11 - Undefined
        uint8_t fill : 2;   // 00 - Empty, 01 - Shaded, 10 - Filled, 11 - Undefined
    private:

    };
}
