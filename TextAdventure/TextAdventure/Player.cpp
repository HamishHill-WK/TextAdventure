#include "Player.h"

Player::Player() {
    name = "NewPlayer";
    health = 5;
    roomCode = 0;
}

std::vector<std::string> Player::breakSentence(const std::string str){
    std::vector<std::string> words;
    std::string trimmedStr = str; // Trim leading and trailing spaces if needed

    // Remove leading spaces
    size_t startPos = trimmedStr.find_first_not_of(' ');
    if (startPos != std::string::npos)
    {
        trimmedStr = trimmedStr.substr(startPos);
    }

    // Remove trailing spaces
    size_t endPos = trimmedStr.find_last_not_of(' ');
    if (endPos != std::string::npos)
    {
        trimmedStr = trimmedStr.substr(0, endPos + 1);
    }

    //remove double spaces
    std::size_t dSpace = trimmedStr.find("  ");
    while (dSpace != std::string::npos)
    {
        trimmedStr.erase(dSpace, 1);
        dSpace = trimmedStr.find("  ");
    }

    size_t lastSpace = 0;
    for (size_t i = 0; i < trimmedStr.length(); i++)
    {
        if (trimmedStr[i] != ' ' && isupper(trimmedStr[i]))
            trimmedStr[i] = tolower(trimmedStr[i]);

        if (trimmedStr[i] == ' ')
        {
            words.push_back(trimmedStr.substr(lastSpace, i - lastSpace));
            lastSpace = i + 1;
        }
    }

    // Add the last word
    if (lastSpace < trimmedStr.length())
    {
        words.push_back(trimmedStr.substr(lastSpace));
    }

    return words;
}

