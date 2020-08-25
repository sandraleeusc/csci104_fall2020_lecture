  
#include <iostream>
#include "str.h"

using namespace std;

void testFunc(Str s)
{
  char c = s[0];
  cout << "In test func, 1st char is " << c << endl;
}

int main()
{
  const Str s1("hello ");
  cout << "s1 is " << s1 << endl;
  Str s2("world");
  cout << "s2 is " << s2 << endl;
  cout << "s1[1]=" << s1[1] << endl;
  s2[0] = 'J';
  cout << "s1+s2 = " << s1+s2 << endl;
  Str s4("world");
  cout << (s1 == s2) << endl;
  cout << (s4 == s4) << endl;
  testFunc(s2);

  return 0;
}
