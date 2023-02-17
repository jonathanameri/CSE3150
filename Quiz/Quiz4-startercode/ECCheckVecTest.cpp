// to build: c++ ECCheckVecTest.cpp -o test
#include <vector>
#include <iostream>
using namespace std;

#include "ECCheckVec.cpp"

int main()
{
  vector<int> vec;
  const int sz = 10;
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
} 


