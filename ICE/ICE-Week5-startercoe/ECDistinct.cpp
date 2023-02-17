#include <vector>
#include <map>
#include <iostream>
using namespace std;

void ECCountDistinct(const vector<int> &listNums, map<int,int> &mapDistinct)
{
  mapDistinct.clear();
  for (auto x : listNums ) 
  {
    ++mapDistinct[x];
  }
}