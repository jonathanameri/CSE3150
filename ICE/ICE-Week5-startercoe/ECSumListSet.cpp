#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  int res = 0;
  // for(auto it = listNums.begin(); it != listNums.end(); it++)
  for( auto x: listNums)
  {

    // res += *it;
    res += x;
  }
  return res;
}

