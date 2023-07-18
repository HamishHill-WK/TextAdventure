#pragma once
#include "Object.h"

class Entity : public Object
{
public:
	Entity();
	Entity(std::string newName, bool newHostile);
	std::string Attack();
	//~Entity();
	int health; 
	bool hostile;
};

