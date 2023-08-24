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

	for (size_t k = 0; k < containerNames.size(); k++) 	//create containers
		Containers.push_back(new Container(containerNames.at(k)));
	
	for (size_t i = 0; i < objects.size(); i++) {
		for(Container* c : Containers)
			if (c->name == insideContainer.at(i)) {
				Containers.back()->Objects.push_back(new Object(objects.at(i), objectDescripts.at(i)));	//add objects to containers if they have been assigned one
				//continue;
			}
			else
				Objects.push_back(new Object(objects.at(i), objectDescripts.at(i)));	//else add the object to room's object vector 
	}

	for (Container* c : Containers)
		Objects.push_back(c);


	for (size_t j = 0; j < npcNames.size(); j++)
		Entities.push_back(new Entity(npcNames.at(j), npcHostile.at(j)));	//add any npcs and set hostility 

	UpdateDescription();
}

std::string Room::EntityActions()
{
	std::string returnMsg = "";

	for (Entity* E : Entities)
		if(E->hostile)
			returnMsg += E->Attack();

	return returnMsg;
}

void Room::UpdateDescription()	//function to change the description of the room based on the presence of items. TODO: add npcs to changing description
{
	std::string itemsDescription = "";
	
	switch (Objects.size())
	{
	case 0:	//if there are no objects itemsDescription is left blank 
		break;
	case 1:
		itemsDescription = " There is a " + Objects[0]->name + ".";
		break;	
	
	case 2:
		itemsDescription = " There is a " + Objects[0]->name + " and a " + Objects[1]->name + ".";
		break;	
	
	case 3:
		itemsDescription = " There is a " + Objects[0]->name + ", a " + Objects[1]->name + " and a ";
		break;
	default:
		itemsDescription = " There is ";
		for (int i = 0; i < Objects.size(); i++) {
			if (i == Objects.size() - 1)			//if the last item has been reached
				itemsDescription += " and a " + Objects[i]->name + ".";
			if (i == Objects.size() - 2)
				itemsDescription += "a " + Objects[i]->name;
			else
				itemsDescription += "a " + Objects[i]->name + ", ";
		}
		break;
	}

	CurrentDescription = Description + itemsDescription;
}
