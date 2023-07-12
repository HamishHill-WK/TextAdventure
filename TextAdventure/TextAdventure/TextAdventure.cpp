#include <iostream>
#include <string>
#include "Player.h"
#include "Room.h"
#include "RoomManager.h"

int main()
{
    std::unique_ptr<RoomManager> RM = std::make_unique<RoomManager>();
    std::unique_ptr<Player> player = std::make_unique<Player>();
    //std::unique_ptr<Room> room = std::make_unique<Room>(true, true, true, true, std::vector<int>{2,3}, "starting room description");
    //std::unique_ptr<Room> room = std::make_unique<Room>(true, true, true, true, std::vector<int>{1,3}, "starting room description");
    //std::unique_ptr<Room> room = std::make_unique<Room>(true, true, true, true, std::vector<int>{1,2}, "starting room description");
    bool playing = true;
    std::string command = "";
    std::string response = "";

    std::cout << "Hello and welcome to text adventure \n Please enter you name: ";
    std::cin >> player->name;
    std::cout << "Hello " << player->name << " let us begin our adventure \n";

    while (playing) {
        std::cin >> command;
        
        if (command == "quit")
            playing = false;

        std::cout << player->commandInput(command);
    }
}
