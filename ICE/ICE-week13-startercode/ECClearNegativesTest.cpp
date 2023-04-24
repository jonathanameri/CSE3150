#include <vector>
#include <iostream>
using namespace std;

#include "ECClearNegatives.cpp"

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

  ECClearNegatives(vec);
  ASSERT_EQ(vec[0],1);
  ASSERT_EQ(vec[1],0);
  ASSERT_EQ(vec[2],0);
  ASSERT_EQ(vec[3],3);
  ASSERT_EQ(vec[4],0);
}
