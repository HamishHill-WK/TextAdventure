#include "Player.h"

Player::Player() {
    RM = std::make_unique<RoomManager>();
    roomCode = RM->rooms.at(0).RoomCode;

    name = "NewPlayer";
}



std::string Player::commandInput(std::string& command)
{
    for (char& c : command) //all chars in command string are changed to lower case for simplicity
        if (isupper(c))
            c = tolower(c);

    if (command == "quit")
        return "Goodbye!";

    if (command == "status") {            //status command returns health stat for player. TODO: return add more information
        return Status();
    }

    if (command == "help")
        return helpMessage;             //returns message containing list of possible actions. 
    

    if(command.find("take") != std::string::npos)   //if the player has entered the take command 
    {     
        return take(command);
    }

    if (command.find("open") != std::string::npos)
    {
        return open(command);
    }

    if (command.find("look at") != std::string::npos) {
        lookAt(command);
    }
    else if (command.find("look") != std::string::npos)
        return RM->rooms.at(roomCode).Description;

    if (command.find("go") != std::string::npos) { //go command found 
        return go(command);
    }

    return invalidMessage;
}

std::string Player::Status()
{
    std::string statusMsg = "Health: " + std::to_string(health) + "\nInventory: ";
    for (Object* o : inventory)
        statusMsg += o->name + "\n";
    return statusMsg;
}

std::string Player::go(std::string command)
{
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

std::string Player::take(std::string command)
{
    for (Object* o : RM->rooms.at(roomCode).Objects)
        if (command.find(o->name) != std::string::npos) {   //cycle through the objects in the room to see if they have entered the name of a valid object
            inventory.push_back(o);
            RM->removeObj(o, roomCode);
            return "grabbed " + o->name;
        }

    for (Container* c : RM->rooms.at(roomCode).Containers)
        if (command.find(c->name) != std::string::npos) {
            inventory.push_back(c);
            return "grabbed " + c->name;
        }

    return "You can't take that!";
}

std::string Player::open(std::string command)
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



std::string Player::lookAt(std::string command)
{
    for (Object* o : RM->rooms.at(roomCode).Objects)
        if (command.find(o->name))
            return o->description;

    for (Object* o : inventory)
        if (command.find(o->name))
            return o->description;

    return "there's nothing like that in here...";
}

std::string Player::hit(std::string command)
{
    return " ";
}

std::string Player::update(std::string& command)
{
    std::string returnMsg = commandInput(command) + "\n";

    if (RM->rooms.at(roomCode).Entities.size() > 0)
        returnMsg += RM->rooms.at(roomCode).EntityActions();

    return returnMsg;
}