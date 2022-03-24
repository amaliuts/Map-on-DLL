#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	this->head = nullptr;
	this->tail = nullptr;
}
//Theta(1)

Map::Map(const Map& other) {
	this->head = other.head;
	this->tail = other.tail;
}
//Theta(1)

Map& Map::operator=(const Map& other) {
	this->head = other.head;
	this->tail = other.tail;
	return *this;
}
//Theta(1)

Map::~Map() {
	struct Node* current = this->head;
	while (current) {
		struct Node* next = current->next;
		delete current;
		current = next;
	}
}
//Theta(n)

TValue Map::add(TKey c, TValue v){
	struct Node* newNode = new Node;
	newNode->elem.first = c;
	newNode->elem.second = v;
	
	if (search(c) == NULL_TVALUE) {
		if (this->head == nullptr) {	//if the map is empty
			this->head = newNode;
			this->tail = newNode;
			this->head->prev = nullptr;
			this->tail->next = nullptr;
		}
		else {
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;
			this->tail->next = nullptr;
		}
		return NULL_TVALUE;
	}
	else {
		int value = search(c);
		struct Node* current = this->head;
		while (current->elem.second != value) {
			current = current->next;
		}
		current->elem.second = v;
		return value;
	}
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

TValue Map::search(TKey c) const{
	if (this->head == nullptr)
		return NULL_TVALUE;
	bool flag = false;
	struct Node* current = this->head;
	while (current != nullptr) {
		if (current->elem.first == c) {
			flag = true;
			break;
		}
		current = current->next;
	}
	if (flag)
		return current->elem.second;
	else
		return NULL_TVALUE;
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)


TValue Map::remove(TKey c){
	if (search(c) == NULL_TVALUE)									//the pair doesn't exist in the map
		return NULL_TVALUE;
	else {
		struct Node* current = this->head;
		while (current->elem.first != c && current != nullptr) {
			current = current->next;
		}
		struct Node* deleted = current;
		if (current != nullptr) {
			if (current == this->head && current == this->tail)		// map has only one pair, which is also the wanted one
				this->head = this->tail = nullptr;
			else if (current == this->head) {						//the wanted pair is the first one
				this->head = this->head->next;
				this->head->prev = nullptr;
			}
			else if (current == this->tail) {						//the wanted pair is the last one
				this->tail = this->tail->prev;
				this->tail->next = nullptr;
			}
			else {													//there are multiple pairs in the map
				current->next->prev = current->prev;
				current->prev->next = current->next;
			}
		}
		return deleted->elem.second;
	}
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

int Map::size() const {
	int size = 0;
	struct Node* current = this->head;
	while (current) {
		current = current->next;
		size++;
	}
	return size;
}
//Theta(n)

bool Map::isEmpty() const{
	return (this->head == nullptr);
}
//Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
//Theta(1)



