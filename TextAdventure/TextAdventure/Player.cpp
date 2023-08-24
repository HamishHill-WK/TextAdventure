#include "Player.h"

Player::Player() {
    RM = std::make_unique<RoomManager>();
    roomCode = RM->rooms.at(0).RoomCode;

    name = "NewPlayer";
}

std::string Player::commandInput(std::string& command)  //function for handling commands 
{
    for (char& c : command) //all chars in command string are changed to lower case for simplicity
        if (isupper(c))
            c = tolower(c);

    if (command.find( "quit") != std::string::npos)
        return "Goodbye!";

    if (command.find( "status") != std::string::npos) {            //status command returns health stat for player. TODO: return add more information
        std::string statusMsg = "Health: " + std::to_string(health) + "\nInventory: ";
        for (Object* o : inventory)
            statusMsg += o->name + "\n";

        return statusMsg;
    }

    if (command.find("help") != std::string::npos)
        return helpMessage;             //returns message containing list of possible actions. 
    

    if(command.find("take") != std::string::npos)   //if the player has entered the take command 
    {     
        for (Container* c : RM->rooms.at(roomCode).Containers) {
            if (command.find(c->name) != std::string::npos) {
                inventory.push_back(c);
                RM->removeCont(c, roomCode);
                RM->removeObj(c, roomCode);
                return "grabbed " + c->name;
            }

            if (c->open) {
                for (Object* o : c->Objects)
                    if (command.find(o->name) != std::string::npos) {
                        inventory.push_back(o);
                        c->removeObj(o);
                        return "grabbed " + o->name;
                    }
            }
        }

        for (Object* o : RM->rooms.at(roomCode).Objects)
            if (command.find(o->name) != std::string::npos) {   //cycle through the objects in the room to see if they have entered the name of a valid object
                inventory.push_back(o);
                RM->removeObj(o, roomCode);
                return "grabbed " + o->name;
            }

        return "You can't take that!";
    }

    if (command.find("open") != std::string::npos)
    {
        for (Container* c : RM->rooms.at(roomCode).Containers)
            if (command.find(c->name) != std::string::npos) {
                c->open = true;
                std::string objectList = "";
                for (Object* o : c->Objects)
                    objectList += o->name + " ";
                return "Inside the " + c->name + " is " + objectList; 
            }

        return "you can't open that...";
    }

    if (command.find("look at") != std::string::npos) {
        for (Object* o : RM->rooms.at(roomCode).Objects)
            if (command.find(o->name) != std::string::npos)
                return o->description;

        for (Object* o : inventory)
            if (command.find(o->name) != std::string::npos)
                return o->description;

        if (command.find("room") != std::string::npos)
            return RM->rooms.at(roomCode).CurrentDescription;

        return "there's nothing like that in here...";
    }
    else if (command.find("look") != std::string::npos)
        return RM->rooms.at(roomCode).CurrentDescription;

    if (command.find("go") != std::string::npos) { //go command found 
        for (std::string s : directions)    //search through list of valid direction north/south/east/west
            if (command.find(s) != std::string::npos) { //if command contains a valid direction
                for (size_t i = 0; i < RM->rooms.at(roomCode).Directions.size(); i++)   //loop through directions found in current room
                    if (s == RM->rooms.at(roomCode).Directions[i]) {    //if direction found command is a valid direction in the room
                        roomCode = RM->rooms.at(roomCode).AdjacentRooms.at(i);  //set new roomcode to corresponding room found in AdjacentRooms vector 

                        return RM->rooms.at(roomCode).CurrentDescription;  //return description of new room 
                    }
            }

        return "can't go that way...";  //if no valid directions are found return this string.
    }

    return invalidMessage; //if no commands are found the invalid command message is returned.
}

std::string Player::update(std::string& command)
{
    std::string returnMsg = commandInput(command) + "\n";

    if (RM->rooms.at(roomCode).Entities.size() > 0)
        returnMsg += RM->rooms.at(roomCode).EntityActions();

    return returnMsg;
}