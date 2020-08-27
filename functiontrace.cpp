// Adapted from Reference: Bjarne Stroustrup. 2014. Programming: Principles and Practice Using C++ (2nd. ed.). 
// Addison-Wesley Professional, pg. 644-645.
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct X {
   int val;
   void out(const string& s, int nv) {
        cerr << this << "->" << s << ":" << val << "(" << nv << ")\n";
   }
   
   X(){out("X()",0); val = 0;}  // default constructor
   X(int v) :val(v) {out("X(int)",v);}
   
   X(const X& x) :val(x.val) {out("X(X&)",x.val);}   // copy constructor
   
   X& operator=(const X&a) {    // copy assignment operator
      out("X::operator=()", a.val); val=a.val; return *this;
   }
   
   ~X() {out("~X()",0);}  // destructor
   };
   
   
   X glob(2); // Global variable
   
   X copy(X a) { return a;}
   
   X copy2(X a) { X aa = a;  return aa;}
   
   X& ref_to(X& a) {return a;}
   
   unique_ptr<X> make(int i) {X a(i); return make_unique<X>(a);}
   
   struct XX {X a; X b;};
   
   // Trace what is output by main. 
   // What is printed to std error?  You can run it and see.
   // What function is called by each statement?
   int main() {
   X loc{4};  // local variable
   X loc2{loc}; // copy construction
   loc = X{5}; // copy assignment
   loc2 = copy(loc); // call by value and return;
   loc2 = copy2(loc);
   X loc3{6};
   X& r = ref_to(loc);
   unique_ptr<X> p1 = make_unique<X>(7);
   p1.reset(); // delete the X from the heap
   p1 = make_unique<X>(8);
   p1.reset(); // delete the X from the heap
   vector<X> v(4);
   XX loc4;
   p1 = make_unique<X>(9);  // create X on heap and then delete it
   p1.reset();
   unique_ptr<X[]> p2 = make_unique<X[]>(5); //create array of X on heap and delete 
   p2.reset(); 
 }
