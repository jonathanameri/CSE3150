// Created by Y. Wu, Jan 28, 2023
// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
#include <vector>
using namespace std;

// (1): counting the number of subsets
int ECSubsetEnumCount(const std::vector<char> &vecChars)
{
  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // your code here ...
}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)
void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets)
{
  // your code here
}
