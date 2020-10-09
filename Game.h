#pragma once

#include <vector>
#include <stdint.h>
#include "Card.h"

namespace Set
{
    class Game
    {
    public:
        Game();
        
        static const uint8_t CARDS_PER_DEAL = 3;
        static const uint8_t STARTING_BOARD_SIZE = 12;
        static const uint8_t NUM_FIELD_PERMUTATIONS = 3;

        std::vector<Card> deck;
        std::vector<Card> board;

    private:

    };// class
}// namespace
