// Merge overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input
// Your code must run no slower than O(nlogn) where n is the number of intervals

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals)
{
    // if (listIntervals.begin() == listIntervals.end())
    // // Copy input into new variable
    std::vector<std::pair<int,int> > newV = listIntervals;
    // sort(newV.begin(), newV.end());

    // int s = newV[0].first;
    // int e = newV[0].second;
    std::pair<int,int> np = newV[0];
    // np.first = s;
    // np.second = e;
    // int s;
    // int e;
    for(auto x : newV)
    {
        if (x.first <= np.second){
            np.second = max(x.second,np.second);
        }
        else
        {
            // std::pair<int,int> nnp = np;
            listNonOverlapIntervals.push_back(np);
            np.first=x.first;
            np.second=x.second;
        }
    }
    listNonOverlapIntervals.push_back(np);

    
}
