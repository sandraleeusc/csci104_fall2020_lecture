#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isParenthesized(string expr) {
    stack<char> s;
    // this is not correct. fix here
    return true;
}

int main()
{
    string test = "(9+8";
    cout << boolalpha << isParenthesized(test) << endl;
    return 0;
}
