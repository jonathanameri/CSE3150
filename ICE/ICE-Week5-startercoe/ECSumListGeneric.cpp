#include <vector>
#include <set>
#include <iostream>
using namespace std;

// I want to have a generic function that can work with any types of numbers 
// AND any type of container. Is this possible?
template < class Container>
typename Container :: value_type ECSumList(const Container &listNums)
{
  typename Container :: value_type res = 0; 
  for (auto x : listNums)
  {
    res += x;
  }
  return res;
}

