// Test ECCopy
#include <vector>
#include <set>
#include <iostream>
using namespace std;

#include "ECCopyGen.cpp"

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


// copy from a set to a set
static void Test1()
{
  set<int> s1, s2;
  s1.insert(1);
  s1.insert(4);
  s1.insert(2);
  ECCopy( s1, s2);
  auto it = s2.begin();
  ASSERT_EQ( *it++, 1 );
  ASSERT_EQ( *it++, 2 );
  ASSERT_EQ( *it++, 4 );
}

// copy from a set to a vector 
static void Test2()
{ 
  set<int> s1;
  s1.insert(1);
  s1.insert(4);
  s1.insert(2);
  vector<int> v1;
  ECCopy( s1, v1);
  auto it = v1.begin();
  ASSERT_EQ( *it++, 1 );
  ASSERT_EQ( *it++, 2 );
  ASSERT_EQ( *it++, 4 );
}


int main()
{
  Test1();
  Test2();
}

