#include "Card.h"

namespace Set
{
    Card::Card()
        : _color(0b11)
        , _number(0b11)
        , _shape(0b11)
        , _fill(0b11)
    {
    }

    Card::Card(uint8_t color, uint8_t number, uint8_t shape, uint8_t fill)
        : _color(color)
        , _number(number)
        , _shape(shape)
        , _fill(fill)
    {
    }

    bool Card::Is_Set(const Card& c1, const Card& c2, const Card& c3)
    {
        // TODO CJR:  check for undefined values?
        bool color_match = c1._color == c2._color && c1._color == c3._color;
        bool color_diff = (c1._color + c2._color + c3._color) == 0b11;

        bool number_match = c1._number == c2._number && c1._number == c3._number;
        bool number_diff = (c1._number + c2._number + c3._number) == 0b11;

        bool shape_match = c1._shape == c2._shape && c1._shape == c3._shape;
        bool shape_diff = (c1._shape + c2._shape + c3._shape) == 0b11;

        bool fill_match = c1._fill == c2._fill && c1._fill == c3._fill;
        bool fill_diff = (c1._fill + c2._fill + c3._fill) == 0b11;

        return (color_match || color_diff) && (number_match || number_diff)
            && (shape_match || shape_diff) && (fill_match || fill_diff);
    }
}// namespace
