
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Implement this function recursively.
// You may use helper functions.
void print_subsets (vector<string> stringSet, int k);


int main()
{
    vector<string> s = {"cat", "dog", "rabbit", "robot"};
    print_subsets(s,3);
    return 0;
}
