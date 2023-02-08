// you are to write a function called ECTernary which takes an integer x and output a string "0", "1", "2" if x = 0, 1, 2 respectively; and "not ternary" if x is equal to other values. The code has a bug. Now fix it.

#include <string>
using namespace std;

string ECTernary(int x)
{
  string res;
  switch(x)
  {
    case 0: res = "0"; 
    case 1: res = "1"; 
    case 2: res = "2"; 
    default: res = "not ternary";
  }
  return res;
}


