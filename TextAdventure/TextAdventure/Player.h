#pragma once
#include "Entity.h"
#include <iostream>
#include "RoomManager.h"
#include <algorithm>
#include "Container.h"

class Player : public Entity
{
public:
	Player();
	//~Player();

	std::vector<Object*> inventory;

	std::unique_ptr<RoomManager> RM;

	std::string update(std::string& command);

private:
	std::string commandInput(std::string& command);

	std::vector<std::string> directions = { "north", "n", "south", "s", "east", "e", "west", "w", "up", "down", "right", "left", "forward", "backwards" };
	std::string helpMessage = { "Command list\n go north, south, east or west\nstatus\ntake 'Object name'\nlook\nlook at 'Object/Entity name'\n hit 'Entity name' with 'object'\n" };
	std::string invalidMessage = "I'm sorry I don't recognise that one. Type 'help' for a list of valid commands \n";
};