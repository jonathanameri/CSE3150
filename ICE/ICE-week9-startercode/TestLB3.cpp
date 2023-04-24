#include <iostream>
using namespace std;

#include "Lightbulb3.cpp"

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
  LightBulb bulb;
  Button bt(bulb);
  ASSERT_EQ(bulb.IsOn(), false);
  bt.Push();
  ASSERT_EQ(bulb.IsOn(), true);
  bt.Push();
  ASSERT_EQ(bulb.IsOn(), false);

}


