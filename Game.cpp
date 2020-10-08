#include <algorithm>
#include "Game.h"

namespace Set
{
    Game::Game()
        : _deck()
        , _board()
    {
    }

    void Game::Initialize_Game(std::default_random_engine random_source)
    {
        _deck.clear();
        _board.clear();

        Create_Deck();

        std::shuffle(std::begin(_deck), std::end(_deck), random_source);

        for (uint8_t i = 0; i < STARTING_BOARD_SIZE; i++)
        {
            Deal_Card();
        }
    }
    
    bool Game::Has_Set()
    {
        auto result = Find_Set();
        return result.has_value();
    }

    std::optional<std::tuple<Card, Card, Card>> Game::Find_Set()
    {
        auto result = std::optional<std::tuple<Card, Card, Card>>();

        auto search_result = Find_Set(0, 1, 2);
        if (search_result.has_value() == true)
        {
            auto [i1, i2, i3] = search_result.value();
            std::tuple<Card, Card, Card> card_tuple = { _board[i1], _board[i2], _board[i3] };
            result.emplace(card_tuple);
        }

        return result;
    }

    // TODO CJR:  breaks if _board.size() == 0, index1 never increments
    //  there should probably be some sort of short-circuit anyways
    std::optional<std::tuple<uint8_t, uint8_t, uint8_t>> Game::Find_Set(uint8_t index1, uint8_t index2, uint8_t index3)
    {
        auto result = std::optional<std::tuple<uint8_t, uint8_t, uint8_t>>();

        if (Is_Set(index1, index2, index3) == true)
        {
            std::tuple<uint8_t, uint8_t, uint8_t> index_tuple = { index1, index2, index3 };
            result.emplace(index_tuple);
        }
        else
        {
            index3++;
            if (index3 >= _board.size())
            {
                index2++;
                index3 = index2 + 1;
            }
            if (index2 >= _board.size() - 1)
            {
                index1++;
                index2 = index1 + 1;
                index3 = index2 + 1;
            }

            if (index1 < _board.size() - 2)
            {
                result = Find_Set(index1, index2, index3);
            }
        }

        return result;
    }

    bool Game::Is_Set(uint8_t index1, uint8_t index2, uint8_t index3)
    {
        bool result = false;
        if (index3 < _board.size())
        {
            result = Card::Is_Set(_board[index1], _board[index2], _board[index3]);
        }
        return result;
    }

    void Game::Add_Cards_To_Board()
    {
        for (int i = 0; i < CARDS_PER_DEAL; i++)
        {
            Deal_Card();
        }
    }

    void Game::Remove_Cards_From_Board(uint8_t index1, uint8_t index2, uint8_t index3)
    {
        _board.erase(_board.begin() + index1);
        _board.erase(_board.begin() + index2);
        _board.erase(_board.begin() + index3);
    }

    void Game::Create_Deck()
    {
        for (uint8_t i = 0; i < MAX_CARD_FIELD_PERMUTATIONS; i++)
        {
            for (uint8_t j = 0; j < MAX_CARD_FIELD_PERMUTATIONS; j++)
            {
                for (uint8_t k = 0; k < MAX_CARD_FIELD_PERMUTATIONS; k++)
                {
                    for (uint8_t l = 0; l < MAX_CARD_FIELD_PERMUTATIONS; l++)
                    {
                        _deck.emplace_back(Card(i, j, k, l));
                    }
                }
            }
        }
    }

    void Game::Deal_Card()
    {
            Card card = _deck.back();
            _deck.pop_back();
            _board.emplace_back(card);
    }
}// namespace
