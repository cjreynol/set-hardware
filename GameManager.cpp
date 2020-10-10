#include <algorithm>
#include "GameManager.h"

namespace Set
{
    void GameManager::Initialize_Game(Game& game, std::default_random_engine random_source)
    {
        game.deck.clear();
        game.board.clear();
        Create_Deck(game);

        std::shuffle(std::begin(game.deck), std::end(game.deck), random_source);

        for (uint8_t i = 0; i < Game::STARTING_BOARD_SIZE; i++)
        {
            Deal_Card(game);
        }
    }

    bool GameManager::Has_Set(const Game& game)
    {
        auto result = Find_Set(game);
        return result.has_value();
    }

    std::optional<std::tuple<Card, Card, Card>> GameManager::Find_Set(const Game& game)
    {
        auto result = std::optional<std::tuple<Card, Card, Card>>();

        auto search_result = Find_Set(game, 0, 1, 2);
        if (search_result.has_value() == true)
        {
            auto [i1, i2, i3] = search_result.value();
            std::tuple<Card, Card, Card> card_tuple = { game.board[i1], game.board[i2], game.board[i3] };
            result.emplace(card_tuple);
        }

        return result;
    }

    std::optional<std::tuple<uint8_t, uint8_t, uint8_t>> GameManager::Find_Set(const Game& game, 
                                                                                uint8_t index1, 
                                                                                uint8_t index2, 
                                                                                uint8_t index3)
    {
        auto result = std::optional<std::tuple<uint8_t, uint8_t, uint8_t>>();

        if (index3 < game.board.size() && Is_Set(game, index1, index2, index3) == true)
        {
            std::tuple<uint8_t, uint8_t, uint8_t> index_tuple = { index1, index2, index3 };
            result.emplace(index_tuple);
        }
        else
        {
            index3++;
            if (index3 >= game.board.size())
            {
                index2++;
                index3 = static_cast<uint8_t>(index2 + 1);
            }
            if (static_cast<size_t>(index2 + 1) >= game.board.size())
            {
                index1++;
                index2 = static_cast<uint8_t>(index1 + 1);
                index3 = static_cast<uint8_t>(index2 + 1);
            }

            if (static_cast<size_t>(index1 + 2) < game.board.size())
            {
                result = Find_Set(game, index1, index2, index3);
            }
        }

        return result;
    }

    void GameManager::Add_Cards_To_Board(Game& game)
    {
        for (int i = 0; i < Game::CARDS_PER_DEAL; i++)
        {
            Deal_Card(game);
        }
    }

    void GameManager::Remove_Cards_From_Board(Game& game, uint8_t index1, uint8_t index2, uint8_t index3)
    {
        game.board.erase(game.board.begin() + index1);
        game.board.erase(game.board.begin() + index2);
        game.board.erase(game.board.begin() + index3);
    }

    void GameManager::Create_Deck(Game& game)
    {
        for (uint8_t i = 0; i < Game::NUM_FIELD_PERMUTATIONS; i++)
        {
            for (uint8_t j = 0; j < Game::NUM_FIELD_PERMUTATIONS; j++)
            {
                for (uint8_t k = 0; k < Game::NUM_FIELD_PERMUTATIONS; k++)
                {
                    for (uint8_t l = 0; l < Game::NUM_FIELD_PERMUTATIONS; l++)
                    {
                        game.deck.emplace_back(Card(i, j, k, l));
                    }
                }
            }
        }
    }

    void GameManager::Deal_Card(Game& game)
    {
        Card card = game.deck.back();
        game.deck.pop_back();
        game.board.emplace_back(card);
    }

    bool GameManager::Is_Set(const Game& game, uint8_t index1, uint8_t index2, uint8_t index3)
    {
        return Is_Set(game.board[index1], game.board[index2], game.board[index3]);
    }

    bool GameManager::Is_Set(const Card& c1, const Card& c2, const Card& c3)
    {
        return (Is_Match(c1.color, c2.color, c3.color) || Is_Diff(c1.color, c2.color, c3.color))
            && (Is_Match(c1.number, c2.number, c3.number) || Is_Diff(c1.number, c2.number, c3.number))
            && (Is_Match(c1.shape, c2.shape, c3.shape) || Is_Diff(c1.shape, c2.shape, c3.shape))
            && (Is_Match(c1.fill, c2.fill, c3.fill) || Is_Diff(c1.fill, c2.fill, c3.fill));
    }

    bool GameManager::Is_Match(uint8_t val1, uint8_t val2, uint8_t val3)
    {
        return val1 == val2 && val2 == val3;
    }

    bool GameManager::Is_Diff(uint8_t val1, uint8_t val2, uint8_t val3)
    {
        return (val1 + val2 + val3) == 0b11;
    }

    GameManager::GameManager()
    {
    }
}// namespace
