#include <iostream>
using namespace std;

#include "SimpleCalc.cpp"

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
  int res1 = SimpleCalc(2,3);
  ASSERT_EQ(res1, 8);
  int res2 = SimpleCalc(2,-3);
  ASSERT_EQ(res2, -6);
}
