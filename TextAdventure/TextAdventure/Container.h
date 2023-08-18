#pragma once
#include "Object.h"
class Container : public Object
{
public:
	Container(std::string newName);
	bool open;
	std::vector<Object*> Objects; 
};