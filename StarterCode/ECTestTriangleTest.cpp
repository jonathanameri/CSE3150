#include <iostream>
using namespace std;

extern int ECTestTriangle(int a, int b, int c);

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

static void Test()
{
  ASSERT_EQ( ECTestTriangle( 3, 4, 5), 0 );
  ASSERT_EQ( ECTestTriangle( -3, 4, 5), -1 );
  ASSERT_EQ( ECTestTriangle( 3, 4, -5), -1 );
  ASSERT_EQ( ECTestTriangle( 0, 3, 3), -1 );
  ASSERT_EQ( ECTestTriangle( 12, 5, 13), 0 );
  ASSERT_EQ( ECTestTriangle( 3, 4, 10), -1 );
  ASSERT_EQ( ECTestTriangle( 7, 4, 3), -1 );
  ASSERT_EQ( ECTestTriangle( 3, 8, 4), -1 );
}


int main()
{
  Test();
}
