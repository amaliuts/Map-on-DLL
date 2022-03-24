#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	this->currentNode = d.head;
}
//Theta(1)


void MapIterator::first() {
	this->currentNode = map.head;
}
//Theta(1)


void MapIterator::next() {
	if (!valid())
		throw exception();
	this->currentNode = this->currentNode->next;;
}
//Theta(1)


TElem MapIterator::getCurrent(){
	if (!valid())
		throw exception();
	TElem e = this->currentNode->elem;
	return e;
}
//Theta(1)


bool MapIterator::valid() const {
	return (this->currentNode != nullptr);
}
//Theta(1)



