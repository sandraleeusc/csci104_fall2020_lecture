#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <memory>

// variables and functions at the point marked below.
class DoubleLL
{
	// holds data about one item in the list.
	struct Item
	{
		int value;

		// links to other items in the circular list.
		std::shared_ptr<Item>  next;
		std::shared_ptr<Item>  prev;

		// default no=argument constructor
		Item():next(nullptr), prev(nullptr) {}

		// default copy constructor
		Item(Item const & other) = default;

		// simple constructor that sets value
		Item(int itemValue): value(itemValue), next(nullptr),prev(nullptr) {}
                ~Item(){} 
	};


	// number of items in the list
	size_t count = 0;

	// pointer to current head of list (index 0)
	std::shared_ptr<Item> head;

        
  std::shared_ptr<Item> tail; 
       
   void remove(std::shared_ptr<Item> p);

public:

	// standard no-argument constructor
	DoubleLL(): head(nullptr), tail(nullptr){}

	// copy constructor
	DoubleLL(DoubleLL const & other);
	
	// assignment operator
	DoubleLL& operator=(DoubleLL const & other);

	// Destructor. Should delete all data allocated by the list. 
	~DoubleLL();

	// Gets item at an index.
	int get(size_t index) const;

	// get length of list.
	size_t size() const;

	// returns true iff the list is empty.
	bool empty() const;

	// Inserts (a copy of) the given item at the end of list.
	void push_back(int value);

	// Sets the item at the given index to have the given value.
	void set(size_t index, int value);

	void remove(size_t index);
  void push_front(int value);
};

#endif
