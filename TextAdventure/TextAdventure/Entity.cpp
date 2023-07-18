#include "Entity.h"
Entity::Entity() {
	health = 5;
	hostile = false;
}

Entity::Entity(std::string newName, bool newHostile) {
	name = newName;
	hostile = newHostile;
}

std::string Entity::Attack()
{
	return "Whack!\n";
}
