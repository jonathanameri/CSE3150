#include <vector>
#include <algorithm>

// Set any negative numbers to zero in the passed-in vector
void ECClearNegatives(std::vector<int> &vec)
{
  // your code here
  // I want to you to write a single line of code
  // (yes, one line but it may be a little long...)
  // Try to practice std::transform

  std::transform(vec.begin(), vec.end(), vec.begin(), [](int x)->int { if (x < 0) return 0; else return x; } );
}
