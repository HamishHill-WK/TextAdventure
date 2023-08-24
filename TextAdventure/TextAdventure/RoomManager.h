#pragma once
#include "Room.h"
#include <fstream>
#include <nlohmann/json.hpp>

class RoomManager
{
public:
    RoomManager();
	inline void loadRooms() {
        std::ifstream f("rooms.json");
        nlohmann::json data = nlohmann::json::parse(f);
        nlohmann::json roomArray = data["rooms"];

        for (nlohmann::json r : roomArray)
            rooms.push_back(Room( r["id"], r["name"], r["connections"], r["description"], 
                                    r["doors"], r["objects"], r["objectDescript"], 
                                    r["insideContainer"], r["containers"],             
                                    r["npc"], r["npchostile"]));
	}

    void removeObj(Object* object, int roomCode);
    void removeCont(Container* object, int roomCode);

	std::vector<Room> rooms;
};

