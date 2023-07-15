#pragma once
#include <string>

class Object
{
public:
	Object();
	//~Object();
	Object(std::string newName, std::string newDescript);
	std::string name;
	std::string description;
	unsigned int roomCode;
};

