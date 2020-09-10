#include <memory>
#include <iostream>
#include "DoubleLL.h"



DoubleLL::DoubleLL(DoubleLL const & other){
         //place holder
}
	
	// assignment operator
DoubleLL& DoubleLL::operator=(DoubleLL const & other){
        // placeholder really
        return *this;
}

	// Destructor. Should delete all data allocated by the list. 
DoubleLL::~DoubleLL(){
  // we'll write this during class

}

	// Gets item at an index.
int DoubleLL::get(size_t index) const {
      //does nothing useful
      return -1;
}

	// get length of list.
size_t DoubleLL::size() const {
       return count;
}

	// returns true iff the list is empty.
bool DoubleLL::empty() const {
	return (count == 0);
}

	// Inserts (a copy of) the given item at the end of list.
void DoubleLL::push_back(int value) {
      //also not useful yet...
}

void DoubleLL::push_front(int value) {
        if (count == 0){
           head = std::make_shared<Item>(value);
           tail = head;
        } else {

           std::shared_ptr<Item> tmp = head;
           head = std::make_shared<Item>(value);
           head->next = tmp;
           if (head->next) head->next->prev = head;
        }
        count++;
}

	// Sets the item at the given index to have the given value.
	// If an index is passed that is >= the number of items in the list, it should "wrap around" back to the first element.
void DoubleLL::set(size_t index, int value){
        // place holder
}

	// Removes the item at the given index from the list.
void DoubleLL::remove(size_t index){
      // also place holder
}

void DoubleLL::remove(std::shared_ptr<Item> p){
// we'll write during class
// to help learn about shared_ptr reference counts
// print the reference count
 std::cout << p.use_count() << std::endl;
}
