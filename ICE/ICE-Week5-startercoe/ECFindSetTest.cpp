#include <vector>
#include <set>
#include <iostream>
using namespace std;

#include "ECFindSet.cpp"

int main()
{
  // create a list of certain size
  const int NUM_INTS = 10000;
  set<int> ss;
  for(int i=0; i<NUM_INTS; ++i)
  {
    ss.insert(i);
  }
  const int NUM_FIND = 1000000;
  for(int i=0; i<NUM_FIND; ++i)
  {
    ECFind(ss,i);
  } 
}

