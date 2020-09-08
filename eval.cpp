#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

//double evaluate(string exp);
/** evaluate(“( ( 5 * 4 ) * (  2 + 3 ) )”) should return the value 100.0 **/
/** evaluate(“( ( 1 + ( 5 * ( 3 + 1 ) ) ) / 4 )”) should return the value 5.25 **/


double evaluate(string expr){
    stringstream s(expr);
    string current_token;
    stack<string> ops;
    stack<double> vals;
// this is not correct. fix here
   return 0;
}



int main()
{
    string test = "( ( 1 + ( 5 * ( 3 + 1 ) ) ) / 4 )";
    cout <<evaluate(test) << endl;
    return 0;
}
