// to build: c++ ECProcVecTest.cpp -o test
#include <iostream>
#include <vector>
using namespace std;

#include "ECProcArray.cpp"

static int cnt = 0;
static void MyProc(int x)
{
  if( x >= 0 )
  {
    ++cnt;
  }
}


int main()
{
  int arr[4] = {-1, -2, 3, 0};

  ECProcArray(arr, 4, MyProc);
  cout << "cnt: " << cnt << endl;
}


