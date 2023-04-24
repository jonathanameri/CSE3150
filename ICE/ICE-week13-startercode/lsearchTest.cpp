#include <vector>
#include <iostream>
using namespace std;

#include "lsearch.cpp"

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

  vector<double> vec = { 1, 3.0/5, 5.0/3, 4, 2 };
  bool f1 = lsearch(vec, 0.6);
  ASSERT_EQ(f1, true);
  bool f2 = lsearch(vec, 1.66666667);
  ASSERT_EQ(f2, true);
  bool f3 = lsearch(vec, 1.7);
  ASSERT_EQ(f3, false);
}