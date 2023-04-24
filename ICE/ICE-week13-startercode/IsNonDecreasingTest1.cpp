#include <vector>
#include <iostream>
using namespace std;
#include "IsNonDecreasing.cpp"

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

int main()
{
std::vector<int> vec1;
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);

ASSERT_EQ(IsNonDecreasing(vec1), true);

vec1.push_back(2);
ASSERT_EQ(IsNonDecreasing(vec1), false);
}

