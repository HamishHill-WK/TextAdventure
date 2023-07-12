#pragma once
#include <vector>
#include "Room.h"
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <iostream>

class RoomManager
{
public:
    RoomManager();
	inline void loadRooms() {
        std::ifstream f("rooms.json");
        nlohmann::json data = nlohmann::json::parse(f);
        nlohmann::json roomArray = data["rooms"];

        for (nlohmann::json r : roomArray)
            rooms.push_back(Room( r["id"], r["name"], r["connections"], r["description"]));

        //for (Room r : rooms) {
        //    std::cout << r.roomCode << "\n";
        //    std::cout << r.Name << "\n";
        //    std::cout << r.adjacentRooms.at(0) << "\n";
        //    std::cout << r.adjacentRooms.at(1) << "\n";
        //    std::cout << r.Description << "\n";
        //}
	}

	std::vector<Room> rooms;
};

