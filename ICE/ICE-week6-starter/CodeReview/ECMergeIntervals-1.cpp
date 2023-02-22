#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals)
{
  // Push the first pair onto interval
  pair<int, int> currInterval(listIntervals[0].first, listIntervals[0].second);
  for (auto itr = listIntervals.begin() + 1; itr != listIntervals.end(); itr++) {
    int first = (*itr).first;
    int second = (*itr).second;

    if (first <= currInterval.second) {
      if (currInterval.second < second)
        currInterval.second = second;
    }
    else {
      listNonOverlapIntervals.push_back(currInterval);
      currInterval.first = first;
      currInterval.second = second;
    }
  }

  listNonOverlapIntervals.push_back(currInterval);
}

