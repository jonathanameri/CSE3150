#include <vector>
#include <iostream>
using namespace std;
#include "IsNonDecreasing.cpp"

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    // cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

int main()
{

std::vector<int> vec1;
const int LARGE_SIZE = 1000000;
for(int i=0; i<LARGE_SIZE; ++i )
{
  vec1.push_back(1-i);
}
for(int i=0; i<1000000; ++i)
{
  vec1.push_back(0);
  ASSERT_EQ(IsNonDecreasing(vec1), false);
}
}
