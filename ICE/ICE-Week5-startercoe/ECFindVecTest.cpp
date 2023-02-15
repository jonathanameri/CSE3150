#include <vector>
using namespace std;

#include "ECFindVec.cpp"

int main()
{
  // create a list of certain size
  const int NUM_INTS = 100;
  vector<int> vec;
  for(int i=0; i<NUM_INTS; ++i)
  {
    vec.push_back(i);
  }
  const int NUM_FIND = 100;
  for(int i=0; i<NUM_FIND; ++i)
  {
    ECFind(vec,i);
  } 
}

