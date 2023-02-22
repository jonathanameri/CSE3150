// Created by Y. Wu, Jan 28, 2023
// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

// (1): counting the number of subsets
int ECSubsetEnumCount(const std::vector<char> &vecChars)
{
  int res = 1;
  map<char, int>FC;
  for(auto i : vecChars)
  {
    FC[i]++;
  }
  for(auto n : FC)
  {
    res = res * (n.second + 1);
  }
  return res;

  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // your code here ...
}

void findSubsets(vector<char> &v, int i, vector<char> &subset, set<vector<char>> &result)
{
  if (!subset.empty()){
    // if(!count(result.begin(),result.end(),subset))
      result.insert(subset);
  // }
  }

  for(unsigned long j = i; j < v.size(); j++)
  {
    subset.push_back(v[j]);
    findSubsets(v, j + 1, subset, result);
    subset.pop_back();
  }
}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)
void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets)
{
  set<vector<char> > result;
  vector<char> subset = {};
  // vector<char> v = const_cast<vector<char>* >(vecChars);
  vector<char> v = vecChars;
  // for(auto i : vecChars){
  //   v.push_back(i);
  // }

  // vector<char> mt = {};
  // listSubsets.push_back(mt);

  findSubsets(v, 0, subset, result);

  for(auto v: result)
  {
    listSubsets.push_back(v);
  }

  // for(auto v: result)
  // {
  //   // for(auto i : v){
  //   //   cout << i << " ";
  //   // }
  //   // cout << "\n";
  //   // cout << '[' << v[0] << ',' << v[1] << ']' << endl;
  //   listSubsets.push_back(v);
  // }

}
