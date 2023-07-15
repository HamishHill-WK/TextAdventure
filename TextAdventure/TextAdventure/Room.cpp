#include "Room.h"

Room::Room(int id, std::string name, std::vector<int> connections, std::string description, std::vector<std::string> doors, std::vector<std::string> objects, std::vector<std::string> objectDescripts)
{
	RoomCode = id;
	Name = name;
	Description = description;
	AdjacentRooms = connections;
	Directions = doors;
	for (size_t i = 0; i < objects.size(); i++)
		Objects.push_back(new Object(objects.at(i), objectDescripts.at(i)));
}
