// Test ECCensor. To compile: c++ ECCensorTest.cpp -o test
#include "ECCensor.cpp"
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;

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

void Test1( )
{
  vector<int> vecIn;
  vecIn.push_back(1);
  vecIn.push_back(-1);
  vecIn.push_back(2);
  vecIn.push_back(5);
  vecIn.push_back(2);
  vector<int> listForbidden;
  listForbidden.push_back(10); 
  listForbidden.push_back(-1); 
  vector<int> listOuts;
  ECCensor(vecIn, listForbidden, 0, listOuts );
  ASSERT_EQ((int)listOuts.size(), 5);
  ASSERT_EQ(listOuts[0], 0);
  ASSERT_EQ(listOuts[1], 1);
  ASSERT_EQ(listOuts[2], 2);
  ASSERT_EQ(listOuts[3], 2);
  ASSERT_EQ(listOuts[4], 5);
}

int main()
{
  Test1();
}
