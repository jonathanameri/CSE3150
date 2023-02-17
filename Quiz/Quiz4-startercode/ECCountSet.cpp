// Created by Y. Wu, Feb 11, 2023
// You are to implement a function called ECCountSet, which takes three parameters: (i) a reference to a set of integers, (ii) integer lb, and (iii) integer ub; this function returns the number of integers that is within the range [lb, ub] (equality allowed) in the set
// For example, for S={1,3, 5, 8, 11}, then ECCountSet(S, 3, 9) would return 3 (3, 5, 8 are within [3,9])
// Note: try to make your code as efficiently as possible; don't waste CPU cycles when you can stop early...

#include <set>
using namespace std;

int ECCountSet(const set<int> &ss, int lb, int ub)
{
  int count = 0;
  auto l = ss.lower_bound(lb);
  auto u = ss.upper_bound(ub);
  for(auto it = l; it != u; it++)
  {
    count++;
  }
  return count;
  
}

