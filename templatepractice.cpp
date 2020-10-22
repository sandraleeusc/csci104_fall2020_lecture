#include <iostream>
#include <memory>
using namespace std;

// Item definition - do NOT change
template <typename T>
struct Item {
    T val;
    shared_ptr<Item<T>> next;
    // Constructor for convenience of testing
    Item<T>(T v, shared_ptr<Item<T>> n): val(v), next(n) {}
};




//1. Write a comparator that will return true if integer is even 

// 2. Write a functor that will increment an integer


//  3. Write a recursive function that will take the head of a templated linked list
//  and apply a comparator to each element of the list and
//  if the comparator is true for the list element with update the value of the 
// element using a functor
template <class T, class Compare, class Change>
void changeCond(shared_ptr<Item<T>> head, Compare comp, Change update);

// Extra to think about: How would this function change if rather than
// working on values in Items the Change functor was passed pointers to Items
// in the list? Can you write necessary functors and signature for the function?
// Can you implement this function to do the same thing as in 3 above.

template<class T>
void printList(shared_ptr<Item<T>> list) {
    shared_ptr<Item<T>> tmp = list;
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp =tmp->next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    shared_ptr<Item<int>> head;
    shared_ptr<Item<int>> curr;
    for(int i = 1; i < argc; i++) {
        if(i==1) {
            head = make_shared<Item<int>>(atoi(argv[i]), nullptr); 
            curr = head;
        } else {
            curr->next = make_shared<Item<int>>(atoi(argv[i]), nullptr); 
            curr = curr->next;
        }
    }

    cout << "Original list: " << endl;
    printList(head);

    // Call your function here using comparators here
    // Be sure to instantiate any functors needed


    cout << "After changing " << endl;
    printList(head);

    // Don't worry about freeing memory.
    // We know it is necessary to avoid memory leaks...
    return 0;

}


