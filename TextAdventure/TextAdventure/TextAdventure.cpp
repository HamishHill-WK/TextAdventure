#include <iostream>
#include <string>
#include "Player.h"
#include "RoomManager.h"

int main()
{
    std::unique_ptr<Player> player = std::make_unique<Player>();    //create player object

    bool playing = true;
    std::string command = "";

    std::cout << "Hello and welcome to text adventure \n Please enter you name: ";
    std::cin >> player->name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters, including the newline
    std::cout << "Hello " << player->name << " let us begin our adventure \n";
    std::cout << player->RM->rooms.at(player->roomCode).Description << "\n";

    while (playing) {
        std::getline(std::cin, command);

        if (command == "quit")
            playing = false;

        std::cout << player->commandInput(command) << "\n";
    }
}
