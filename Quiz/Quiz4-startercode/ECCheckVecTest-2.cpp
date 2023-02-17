// to build: c++ ECCheckVecTest.cpp -o test
#include <vector>
#include <iostream>
using namespace std;

#include "ECCheckVec.cpp"

int main()
{
  vector<int> vec;
  const int sz = 1000000;
  for(int i=0; i<sz; ++i)
  {
    vec.push_back(i);
  }
  bool f1 = ECCheckVec(vec, 3);
  if( f1 )
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }
  f1 = ECCheckVec(vec, 13);
  if( f1 )
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  // now a larger test case
  const int NUM = 1000;
  int numTrue = 0;
  for(int i=0; i<NUM; ++i)
  {
    bool f = ECCheckVec(vec, sz);
    if( f )
    {
      ++numTrue;
    }
  }
  cout << "Number of true: " << numTrue << endl;
} 


