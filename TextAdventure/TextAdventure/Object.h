#pragma once
#include <string>
#include <vector>

enum Weight { light, medium, heavy, immovable };

class Object
{
public:
	Object();
	//~Object();
	Object(std::string newName, std::string newDescript);
	std::string name;
	std::string description;
	unsigned int roomCode;
	Weight weight; 
};

