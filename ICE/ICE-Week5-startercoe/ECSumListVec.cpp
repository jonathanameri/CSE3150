#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  int res = 0;
  for (auto x : listNums){
    res += x;
  }
  return res;
}