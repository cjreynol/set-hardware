#pragma once

#include <optional>
#include <random>
#include <stdint.h>
#include "Card.h"
#include "Game.h"

using std::default_random_engine;
using std::optional;
using std::tuple;

namespace Set
{
    class GameManager
    {
    public:
        /// <summary>
        /// Clear the deck and board and reset the game to begin play.
        /// </summary>
        static void Initialize_Game(Game& game, default_random_engine random_source);

        static bool Has_Set(const Game& game);
        static optional<tuple<Card, Card, Card>> Find_Set(const Game& game);
        static bool Is_Set(const Game& game, uint8_t index1, uint8_t index2, uint8_t index3);
        static void Add_Cards_To_Board(Game& game);
        static void Remove_Cards_From_Board(Game& game, uint8_t index1, uint8_t index2, uint8_t index3);
        
    private:
        GameManager();

        static optional<tuple<uint8_t, uint8_t, uint8_t>> Find_Set(const Game& game, uint8_t index1, uint8_t index2, uint8_t index3);

        /// <summary>
        /// Populates game deck with 81 possible card combinations
        /// </summary>
        static void Create_Deck(Game& game);

        /// <summary>
        /// Move card from the deck to the board.
        /// </summary>
        static void Deal_Card(Game& game);

        /// <summary>
        /// Determines if the triple is a "set" by all matching or all different across all 4 categories.
        /// Undefined values are not accounted for, will likely cause incorrect results.
        /// </summary>
        static bool Is_Set(const Card& c1, const Card& c2, const Card& c3);

        static bool Is_Match(uint8_t val1, uint8_t val2, uint8_t val3);
        static bool Is_Diff(uint8_t val1, uint8_t val2, uint8_t val3);
    };// class
}// namespace
