#include <vector>
#include <iostream>
using namespace std;
#include "ECCountNonNegative.cpp"

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

  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(-2);
  vec.push_back(0);
  vec.push_back(3);
  vec.push_back(-4);

  int cnt = ECCountNonNegatives(vec);
  ASSERT_EQ(cnt, 3);
}
