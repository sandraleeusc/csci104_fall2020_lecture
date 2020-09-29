
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T, typename comp>
   T mymax(const T& a, const T& b, comp test)
{
  // Implement your function to use your comparator
   return b;
}
   
   
 // Write a comparator to compare the size of 2 vectors of ints and return true if 
//  and only if the first parameter is the larger sized vector 
 
 
 // Write a comparator to compare the sum of two vectors of  ints and return
 // true if and only if the first parameter  vector has the larger sum
 
 


int main(){
    vector<int> a(10);
    vector<int> b(11);
    
    for (int i = 0; i < 10; i++ ) {
        a[i] = 2*(i+1);
        b[i] = i+1;
    }
    
    b[10] = 11;

     // Instantiate your size comparator
     // Instantiate your sum comparator
    // Test each comparator with the vectors a, b and the function max
}
