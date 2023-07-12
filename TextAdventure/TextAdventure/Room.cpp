#include "Room.h"

Room::Room(int id, std::string name, std::vector<int> connections, std::string description)
{
	roomCode = id;
	Name = name;
	Description = description;
	adjacentRooms = connections;
}
