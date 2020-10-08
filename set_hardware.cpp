#include <iostream>
#include <string>
#include "Game.h"

int main()
{
    Set::Game game = Set::Game();
    auto result = game.Find_Set();

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

    std::cout << std::endl << std::endl << "Press enter to continue;";
    std::getline(std::cin, x);
}
