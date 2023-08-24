#include <iostream>
#include <string>
#include "Player.h"
#include "RoomManager.h"

int main()
{
    std::unique_ptr<Player> player = std::make_unique<Player>();    //create player object

    std::string command = "";

    std::cout << "Hello and welcome to text adventure \nPlease enter your name: ";
    std::cin >> player->name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters, including the newline
    std::cout << "Hello " << player->name << " let us begin our adventure \n";
    std::cout << player->RM->rooms.at(player->roomCode).CurrentDescription << "\n";

    while (true) {
        std::cout << "I << : ";

        std::getline(std::cin, command);

        std::cout << "O >> : " << player->update(command) << "\n";

        if (command == "quit")
            break;
    }
}