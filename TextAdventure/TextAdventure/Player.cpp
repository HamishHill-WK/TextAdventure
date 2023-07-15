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

    if (command == "quit")
        return "Goodbye!";


    if (command == "status") {            //status command returns health stat for player. TODO: return add more information
        std::string statusMsg = "Health: " + std::to_string(health) + "\nInventory: ";
        for (Object* o : inventory)
            statusMsg += o->name + "\n";

        return statusMsg;
    }

    if (command == "help")
        return helpMessage;             //returns message containing list of possible actions. 
    

    if(command.find("take") != std::string::npos)
    {
        for (Object* o : RM->rooms.at(roomCode).Objects)
            if (command.find(o->name) != std::string::npos) {
                inventory.push_back(o);
                RM->removeObj(o, roomCode);
                return "grabbed " + o->name;
            }

        return "You can't take that!";
    }

    if (command.find("look at") != std::string::npos) {
        for (Object* o : RM->rooms.at(roomCode).Objects)
            if (command.find(o->name))
                return o->description;

        for (Object* o : inventory)
            if (command.find(o->name))
                return o->description;

        return "there's nothing like that in here...";
    }

    if (command.find("go") != std::string::npos) { //go command found 
        for (std::string s : directions)    //search through list of valid direction north/south/east/west
            if (command.find(s) != std::string::npos) { //if command contains a valid direction
                for (size_t i = 0; i < RM->rooms.at(roomCode).Directions.size(); i++)   //loop through directions found in current room
                    if (s == RM->rooms.at(roomCode).Directions[i]) {    //if direction found command is a valid direction in the room
                        roomCode = RM->rooms.at(roomCode).AdjacentRooms.at(i);  //set new roomcode to corresponding room found in AdjacentRooms vector 

                        return RM->rooms.at(roomCode).Description;  //return description of new room 
                    }
            }

        return "can't go that way...";
    }

    return invalidMessage;
}

