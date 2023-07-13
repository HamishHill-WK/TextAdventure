#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>
#include "RoomManager.h"
#include <algorithm>

class Player : public Entity
{
private:

public:
	Player();
	std::string helpMessage = "Command list \n go north, south, east or west \n status \n take 'Object name' \n look at 'Object/Entity name' \n hit 'Entity name' \n";
	std::string invalidMessage = "I'm sorry I don't recognise that one. Type 'help' for a list of valid commands \n";

	std::vector<std::string> validCommands;
	std::vector<std::string> directions = { "north", "south", "east", "west" };

	void move();
	void hit();
	void status();
	void take();
	std::vector<Object> inventory;

	std::unique_ptr<RoomManager> RM;

	std::string commandInput(std::string& command);
};

