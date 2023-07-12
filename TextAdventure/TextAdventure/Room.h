#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class Room
{
public:
	Room(int id, std::string name,
		std::vector<int> connections, 
		std::string description);

	std::string Name;

	unsigned int roomCode;

	std::vector<int> adjacentRooms;

	std::vector<Entity> Entities;

	std::string Description;
};

