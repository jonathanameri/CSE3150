// Recall in PA3, you want to find a common number in two arrays
// That function only assumes integer type; what about others: char, string, long, etc?
// Now implement a more generic common number finding function that works for different types, and we change the input type to vector
#include <vector>
#include <algorithm>
using namespace std;

template < class T >
bool ECCommonNumber(const vector<T> &listA, const vector<T> &listB, T &val)
{
  for( auto x : listA)
  {
    for ( auto y : listB)
    {
      if ( x == y){
        val = x;
        return true;
      }
    }
  }
  return false;
}

