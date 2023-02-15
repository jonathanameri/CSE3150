#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#include "ECCommonNumberGen.cpp"

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

void Test1()
{
  // test finding an integer in vector
  vector<int> v1, v2;
  v1.push_back(3);
  v1.push_back(2);
  v1.push_back(5);
  v2.push_back(7);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(1);
  int com = -1;
  bool f = ECCommonNumber( v1, v2, com );
  ASSERT_EQ(f, true);
  ASSERT_EQ(com, 3);
}

void Test2()
{
  // find a string in a vector of strings
  vector<string> v1, v2;
  v1.push_back("CSE");
  v1.push_back("3150");
  v1.push_back("stuff");
  v2.push_back("PHIL");
  v2.push_back("mine");
  v2.push_back("3150");
  string com;
  bool f = ECCommonNumber( v1, v2, com );
  ASSERT_EQ(f, true);
  ASSERT_EQ(com, string("3150"));
}

int main()
{
  Test1();
  Test2();
}

