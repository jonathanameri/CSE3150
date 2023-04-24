#include <vector>
#include <algorithm>

int cnt = 0;

void myCount(int x)
{
  if(x >= 0)
  {
    cnt++;
  }
}

// count and return the number of integers in vec that are non-negative
int ECCountNonNegatives(const std::vector<int> &vec)
{
  int cnt = 0;
  //Brackets called 'capture'; allows u to access variables outside of the lambda
  //Capture by reference vs capture by value, default is by value

  std::for_each(vec.begin(), vec.end(), [&cnt](int x ){ if(x >= 0) cnt++; } );  
  return cnt;
}
