// Created by Y. Wu, Feb 7, 2023
// We get back to the ternary test
// You are to implement a different function called ECTernary2, which takes an integer x and return an integer. You would return x if x is 0, 1, or 2
// Otherwise, you would throw an exception in the form of C++ string "not ternary" if x is equal to other values. 
// Note: you must throw in the form of C++ string. 
// Check the provided test file: ECSimpleExceptionTest.cpp
#include <string>
using namespace std;


int ECTernary2(int x)
{
  if(x == 0 || x == 1 || x == 2) return x;
  throw string("not ternary");
  return 0;
}

