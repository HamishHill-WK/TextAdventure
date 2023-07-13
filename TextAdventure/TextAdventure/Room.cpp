#include "Room.h"

Room::Room(int id, std::string name, std::vector<int> connections, std::string description, std::vector<std::string> doors)
{
	RoomCode = id;
	Name = name;
	Description = description;
	AdjacentRooms = connections;
	Directions = doors;
}
