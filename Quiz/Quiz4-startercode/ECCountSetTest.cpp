#include <set>
#include <iostream>
using namespace std;

#include "ECCountSet.cpp"

int main()
{
  set<int> ss;
  ss.insert(1);
  ss.insert(8);
  ss.insert(5);
  ss.insert(11);
  ss.insert(3);
  int cnt = ECCountSet(ss, 3, 9);
  // should be 3
  cout << cnt << endl;
}

