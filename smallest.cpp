
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//partition of quicksort
template <typename T>
int partition(vector<T>& a, int l, int r)
{	 
      int i= l; 
      // set pivot         
      T p = a [ r ] ; 
      for ( int j = l ; j < r ; j++) {
      // moving pivot to correct position
         if ( a [ j ] <= p ) {
             swap ( a[i] ,a[j] ) ; 
             i ++; 
         } 
      } 
      swap ( a[i] ,a[r]  ) ; 
   // return index where pivot is in correct position
     return i ; 
}


// returns the (k+1)-th smallest element
// What is the runtime of quantile?
// Set up the recurrence
// Solve the recurrence
// You may assume that sort on a very small list on line 42
// takes O(1).

template <typename T>
T quantile (vector<T>& a, int left, int right, int k)
{ 

  if (right <= left + 10) //Sort small array directly
  {  
     sort(a.begin()+left, a.begin()+right);  // Sorts a between left and right.
    return a[k+left];
  }
    else   // we still have a pretty big array left
  {
    int smallsize = (right-left)/5;
    vector<T> b(smallsize);

 
    for (int i = 0; i < smallsize; i ++)
       b[i] = quantile (a, left+5*i, left+5*(i+1)-1, 2);

   
    T pivot = quantile (b, 0, smallsize-1, smallsize/2);

    
    int p;
    for (p = left; p <= right; p++)
    {
        if (a[p] == pivot) break;
    }
   
    swap (a[p], a[right]);

    int m = partition (a, left, right);

    if (left+k == m) return a[m];
    else if (left+k < m) return quantile (a, left, m-1, k);
    else return quantile (a, m+1, right, k-(m+1-left));
  }
}



int main()
{
    vector<int> test;
    for (int i= 1; i <= 100; i++){
         test.push_back(2*i);
    }
    
    int testing = quantile(test, 0,99, 0);
    cout << testing << endl;
    return 0;
}
