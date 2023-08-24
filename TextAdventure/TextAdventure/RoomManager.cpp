#include "RoomManager.h"

RoomManager::RoomManager()
{
	loadRooms();
}

void RoomManager::removeObj(Object* object, int roomCode)
{
	// Use std::remove() to shift the objects and get the iterator to the new end, this is done so that memory is deallocated on deleting an object.
	auto newEnd = std::remove(rooms.at(roomCode).Objects.begin(), rooms.at(roomCode).Objects.end(), object);

	// Erase the removed objects by resizing the vector
	rooms.at(roomCode).Objects.erase(newEnd, rooms.at(roomCode).Objects.end());

	rooms.at(roomCode).UpdateDescription();
}

void RoomManager::removeCont(Container* object, int roomCode)
{
	// Use std::remove() to shift the objects and get the iterator to the new end, this is done so that memory is deallocated on deleting an object.
	auto newEnd = std::remove(rooms.at(roomCode).Objects.begin(), rooms.at(roomCode).Objects.end(), object);
	auto newEnd1 = std::remove(rooms.at(roomCode).Containers.begin(), rooms.at(roomCode).Containers.end(), object);

	// Erase the removed objects by resizing the vector
	rooms.at(roomCode).Objects.erase(newEnd, rooms.at(roomCode).Objects.end());
	rooms.at(roomCode).Containers.erase(newEnd1, rooms.at(roomCode).Containers.end());

	rooms.at(roomCode).UpdateDescription();
}
