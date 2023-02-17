#include <vector>
#include <set>
#include <iostream>
using namespace std;

#include "ECCountCommonItems.cpp"

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(2);
  vector<int> v2;
  v2.push_back(0);
  v2.push_back(3);
  v2.push_back(-1);
  set<int> s;
  s.insert(5);
  s.insert(1);
  s.insert(8);
  s.insert(2);
  set<int> s2;
  s2.insert(0);
  s2.insert(1);
  s2.insert(3);
  s2.insert(2);

  // should be 2
  int cnt = ECCountCommonItems(v, s);
  cout << "common: " << cnt << endl;
  // should be 3 
  cnt = ECCountCommonItems(v, s2);
  cout << "common: " << cnt << endl;
  // should be 1 
  cnt = ECCountCommonItems(v, v2);
  cout << "common: " << cnt << endl;
}

