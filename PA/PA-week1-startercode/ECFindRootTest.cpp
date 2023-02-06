// Test code for ECFindRoot
// To build: c++ ECFindRootTest.cpp -o test
// To test: ./test

#include <iostream>
using namespace std;

#include "ECFindRoot.cpp"

int main()
{
  int test1[] = {4, -4, 1};
  // root = 2 for 4-4x+x^2=0
  cout << ECFindRoot(test1, 2, 10) << endl;
  // should return -1 (no root)
  int test2[] = {1, -3, 1};
  cout << ECFindRoot(test2, 2, 10) << endl;
  // should return -1
  // cout << ECFindRoot(test2, 0, 10) << endl;

  //my own tests
  int test3[] = {6, -7, 0, 1};
  cout << ECFindRoot(test3, 3, 10) << endl;
  // cout << "test " << endl;
}