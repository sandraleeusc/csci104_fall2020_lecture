#include <memory>
#include <iostream>
#include "selectionsort.h"
using namespace std;

shared_ptr<Item> findMin(shared_ptr<Item>& head){
   
} 

shared_ptr<Item> LLSelectionSort(shared_ptr<Item> head){
   
} 

int main(){

   shared_ptr<Item> a = make_shared<Item>(2);
 
   shared_ptr<Item> b = make_shared<Item>(11);
   shared_ptr<Item> c = make_shared<Item>(23); 
   shared_ptr<Item> d = make_shared<Item>(3); 
   a->next = b;
   b->prev = a;
   b->next = c;
   c->prev = b;
   d->prev = c;
   c->next = d;

  shared_ptr<Item> sorted = LLSelectionSort(a);

  shared_ptr<Item> temp = sorted;

  while (temp != nullptr){

      cout << "Current value " << temp->getValue() << endl;
      temp = temp->next;
  }
	
  // This code has memory leaks. Why? How to fix?

}
