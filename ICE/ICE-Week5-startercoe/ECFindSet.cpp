#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool ECFind(const set<int> &listNums, int x)
{
  return listNums.find(x) != listNums.end();
}

