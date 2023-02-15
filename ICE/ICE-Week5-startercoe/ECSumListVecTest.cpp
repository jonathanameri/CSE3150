#include <vector>
#include <iostream>
using namespace std;

#include "ECSumListVec.cpp"

int main()
{
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(1);
  int sum = ECSumList(vec);
  cout << "sum: " << sum << endl;
}

