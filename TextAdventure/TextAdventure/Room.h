#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class Room
{
public:
	Room(int id, std::string name,
		std::vector<int> connections,
		std::string description,
		std::vector<std::string> doors,
		std::vector<std::string> objects,
		std::vector<std::string> objectDescripts);

	std::string Name;

	unsigned int RoomCode;

	bool North;
	bool South;
	bool East;
	bool West;

	std::vector<std::string> Directions;

	std::vector<int> AdjacentRooms;

	std::vector<Object*> Objects;

	std::vector<Entity> Entities;

	std::string Description;
};

