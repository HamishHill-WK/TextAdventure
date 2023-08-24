#include "Container.h"

Container::Container(std::string newName)
{
	name = newName;
	open = false;
}

void Container::removeObj(Object* object)
{
	// Use std::remove() to shift the objects and get the iterator to the new end, this is done so that memory is deallocated on deleting an object.
	auto newEnd = std::remove(Objects.begin(), Objects.end(), object);

	// Erase the removed objects by resizing the vector
	Objects.erase(newEnd, Objects.end());
}
