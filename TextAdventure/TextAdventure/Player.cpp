#include "Player.h"

Player::Player() {
    RM = std::make_unique<RoomManager>();
    roomCode = RM->rooms.at(0).RoomCode;

    name = "NewPlayer";
    health = 5;
}

std::string Player::commandInput(std::string& command)
{
    for (char& c : command) //all chars in command string are changed to lower case for simplicity
        if (isupper(c))
            c = tolower(c);

    if (command.find(' ') == std::string::npos) {

        if (command == "status")            //status command returns health stat for player. TODO: return add more information
            return std::to_string(health);

        if (command == "help")
            return helpMessage;             //returns message containing list of possible actions. 
    }

    else if (command.find('go') != std::string::npos) { //go command found 
        for (std::string s : directions)    //search through list of valid direction north/south/east/west
            if (command.find(s) != std::string::npos) { //if command contains a valid direction
                for (size_t i = 0; i < RM->rooms.at(roomCode).Directions.size(); i++)   //loop through directions found in current room
                    if (s == RM->rooms.at(roomCode).Directions[i]) {    //if direction found command is a valid direction in the room
                        roomCode = RM->rooms.at(roomCode).AdjacentRooms.at(i);  //set new roomcode to corresponding room found in AdjacentRooms vector 

                        return RM->rooms.at(roomCode).Description;  //return description of new room 
                    }
            }

        return "can't go that way";
    }

    return invalidMessage;
}

