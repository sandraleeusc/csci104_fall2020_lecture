#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Write a recursive function that returns all products of the subsets
// of set of primes in the vector primes
// You may use helper functions
// Trace your function on the set {2,3}
vector<int> allProducts(const vector<int>& primes) 
{
  vector<int> a;
  return a;
}

void sortAndPrint(vector<int> nums){
   sort(nums.begin(), nums.end());
   for(unsigned int i=0; i < nums.size(); i++){
      cout << nums[i] << " ";  
   }
   cout << endl;

}

int main(int argc, char* argv[]) {
   // Answers go in this vector
   vector<int> products;
   
   vector<int> primes1;
   products = allProducts(primes1);
   sortAndPrint(products);
   
   products.clear();
   vector<int> primes2;
   primes2.push_back(2); primes2.push_back(5);
   products = allProducts(primes2);
   sortAndPrint(products);

   products.clear();
   vector<int> primes3;
   primes3.push_back(2); primes3.push_back(3); primes3.push_back(7); 
   products = allProducts(primes3);
   sortAndPrint(products);

   products.clear();
   vector<int> primes4;
   primes4.push_back(2); primes4.push_back(3); primes4.push_back(5); primes4.push_back(11);
   products = allProducts(primes4);
   sortAndPrint(products);

   return 0;   
}
