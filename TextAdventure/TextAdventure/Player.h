#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>

class Player : public Entity
{
private:

public:
	Player();
	std::string helpMessage = "Command list \n go north, south, east or west \n status \n take 'Object name' \n look at 'Object/Entity name' \n hit 'Entity name' \n";
	std::string invalidMessage = "I'm sorry I don't recognise that one. Type 'help' for a list of valid commands \n";
	std::vector<std::string> breakSentence(const std::string str);

	std::vector<std::string> validCommands;
	std::vector<std::string> directions = { "north", "south", "east", "west" };

	void move();
	void hit();
	void status();
	void take();
	std::vector<Object> inventory;

	inline std::string commandInput(std::string& command) {
		for (char &c : command)
			if(isupper(c))
				c = tolower(c);

		if (command.find(' ') == std::string::npos) {

			if (command == "status")
				return std::to_string(health);

			if (command == "help")
				return helpMessage;
		}
		else if (command.find('go') != std::string::npos) {
				for (std::string s : directions)
					if (command.find(s) != std::string::npos) {
						//move();
						break;
					}
			
		}
		else {
			return invalidMessage;
		}
	}
};

