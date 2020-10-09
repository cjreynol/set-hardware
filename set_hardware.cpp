#include <iostream>
#include <random>
#include <string>

#include "Game.h"
#include "GameManager.h"

int main()
{
    Set::Game game = Set::Game();
    Set::GameManager::Initialize_Game(game, std::default_random_engine());
    auto result = Set::GameManager::Find_Set(game);

    std::string x;
    if (result.has_value())
    {
        x = "Found one.";
    }
    else
    {
        x = "No set found.";
    }
    std::cout << x << std::endl;

    std::cout << std::endl << std::endl << "Press enter to continue.";
    std::getline(std::cin, x);
}
