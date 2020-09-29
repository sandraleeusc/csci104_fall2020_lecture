#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <memory>

struct Item 
{
public:

	// constructor taking a value (you don't have to code this)
	Item(int value): _value(value) {}

	// default copy constructor (you don't have to code this)
	Item(Item const & other) = default;

	// get the int stored in the item
	int getValue() const { return _value; }

	// pointers to next and previous items in the list.
	std::shared_ptr<Item> next;
	std::shared_ptr<Item> prev;

private:
	int _value;
};

// Given a list, returns a pointer to the smallest item and removes it
// from the list. If the head is the minimum then it updates the head
// ptr.
// Returns nullptr if and only if head is nullptr.
std::shared_ptr<Item> findMin(std::shared_ptr<Item>& head);

// Sorts the given list in ascending order and returns the new head.
// Returns nullptr iff head is nullptr.
std::shared_ptr<Item> LLSelectionSort(std::shared_ptr<Item> head);

#endif
