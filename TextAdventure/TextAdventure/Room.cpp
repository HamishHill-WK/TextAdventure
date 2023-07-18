#include "Room.h"
#include "Container.h"
Room::Room(int id, std::string name, std::vector<int> connections,
	std::string description, std::vector<std::string> doors,
	std::vector<std::string> objects, std::vector<std::string> objectDescripts,
	std::vector<std::string> insideContainer, std::vector<std::string> containerNames,
	std::vector<std::string> npcNames, std::vector<bool> npcHostile)
{
	RoomCode = id;
	Name = name;
	Description = description;
	AdjacentRooms = connections;
	Directions = doors;

	for (size_t k = 0; k < containerNames.size(); k++) {
		Containers.push_back(new Container(containerNames.at(k)));
	}

	for (size_t i = 0; i < objects.size(); i++) {
		for(Container* c : Containers)
			if (c->name == insideContainer.at(i)) {
				Containers.back()->Objects.push_back(new Object(objects.at(i), objectDescripts.at(i)));
				continue;
			}

		Objects.push_back(new Object(objects.at(i), objectDescripts.at(i)));
	}

	for (size_t j = 0; j < npcNames.size(); j++)
		Entities.push_back(new Entity(npcNames.at(j), npcHostile.at(j)));
}

std::string Room::EntityActions()
{
	std::string returnMsg = "";

	for (Entity* E : Entities)
		if(E->hostile)
			returnMsg += E->Attack();

	return returnMsg;
}