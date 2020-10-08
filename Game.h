#pragma once

#include <optional>
#include <random>
#include <vector>
#include <stdint.h>
#include "Card.h"

namespace Set
{
    class Game
    {
    public:
        Game();

        void Initialize_Game(std::default_random_engine random_source);
        bool Has_Set();
        std::optional<std::tuple<Card, Card, Card>> Find_Set();
        bool Is_Set(uint8_t index1, uint8_t index2, uint8_t index3);
        void Add_Cards_To_Board();
        void Remove_Cards_From_Board(uint8_t index1, uint8_t index2, uint8_t index3);

    private:
        const uint8_t CARDS_PER_DEAL = 3;
        const uint8_t STARTING_BOARD_SIZE = 12;
        const uint8_t MAX_BOARD_SIZE = 18;  // near impossible for there to not be a set at this size
        const uint8_t MAX_DECK_SIZE = 81;
        const uint8_t MAX_CARD_FIELD_PERMUTATIONS = 3;

        std::vector<Card> _deck;
        std::vector<Card> _board;

        std::optional<std::tuple<uint8_t, uint8_t, uint8_t>> Find_Set(uint8_t index1, uint8_t index2, uint8_t index3);
        void Create_Deck();

        /// <summary>
        /// Move card from the deck to the board.
        /// </summary>
        void Deal_Card();
    };// class
}// namespace
