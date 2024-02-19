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

	std::string update(std::string& command);
	std::unique_ptr<RoomManager> RM;

private:
	std::string commandInput(std::string& command);
	std::string Status();
	std::string go(std::string command);
	std::string take(std::string command);
	std::string lookAt(std::string command);
	std::string hit(std::string command);
	std::string open(std::string command);

	std::vector<Object*> inventory;
	std::vector<std::string> directions = { "north", "n", "south", "s", "east", "e", "west", "w", "up", "down", "right", "left", "forward", "backwards" };
	std::string helpMessage = { "Command list\ngo north, south, east or west\nstatus\ntake 'Object name'\nlook\nlook at 'Object/Entity name'\nhit 'Entity name' with 'object'\n" };
	std::string invalidMessage = "I'm sorry I don't recognise that one. Type 'help' for a list of valid commands\n";
};