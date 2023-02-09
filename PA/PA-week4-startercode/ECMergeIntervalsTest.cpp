// Merge overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input
// Your code must run no slower than O(nlogn) where n is the number of intervals

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

extern void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals);

// test it out
int main()
{
    // case 1:  [[1,3],[2,6],[8,10],[15,18]]
    pair<int,int> pp1(1,3), pp2(2,6), pp3(8, 10), pp4(15,18), pp5(16,18);
    vector<pair<int,int> > listIVs1;
    listIVs1.push_back(pp1);
    listIVs1.push_back(pp2);
    listIVs1.push_back(pp3);
    listIVs1.push_back(pp4);
    listIVs1.push_back(pp5);
    vector<pair<int,int> > listIVs1Out;
    ECMergeIntervals(listIVs1, listIVs1Out);
    cout << "List of non-overlapping intervals: ";
    for(unsigned int i=0; i<listIVs1Out.size(); ++i)
    {
        cout << "[" << listIVs1Out[i].first << "," << listIVs1Out[i].second << "] ";
    }
    cout << endl;
    
    // case 2: [[1,4],[4,5],[3,7]]
    pair<int,int> ppb1(1,4), ppb2(4,5), ppb3(3,7);
    vector<pair<int,int> > listIVs2;
    listIVs2.push_back(ppb1);
    listIVs2.push_back(ppb2);
    listIVs2.push_back(ppb3);
    vector<pair<int,int> > listIVs2Out;
    ECMergeIntervals(listIVs2, listIVs2Out);
    cout << "List of non-overlapping intervals: ";
    for(unsigned int i=0; i<listIVs2Out.size(); ++i)
    {
        cout << "[" << listIVs2Out[i].first << "," << listIVs2Out[i].second << "] ";
    }
    cout << endl;
    
    // case 2: [[1,6],[2,5],[3,5]]
    pair<int,int> ppc1(1,6), ppc2(2,5), ppc3(3,5), ppc4(8,9), ppc5(8,9);
    vector<pair<int,int> > listIVs3;
    listIVs3.push_back(ppc1);
    listIVs3.push_back(ppc2);
    listIVs3.push_back(ppc3);
    listIVs3.push_back(ppc4);
    listIVs3.push_back(ppc5);
    vector<pair<int,int> > listIVs3Out;
    ECMergeIntervals(listIVs3, listIVs3Out);
    cout << "List of non-overlapping intervals: ";
    for(unsigned int i=0; i<listIVs3Out.size(); ++i)
    {
        cout << "[" << listIVs3Out[i].first << "," << listIVs3Out[i].second << "] ";
    }
    cout << endl;
    
    return 0;
} 
