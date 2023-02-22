#include <iostream>
#include "ECMatrix.h"
using namespace std;
#include <chrono>
using namespace std::chrono;

int main()
{
  const int NR=10000;
  const int NC=10000;
  ECMatrix mat1(NR, NC);
  mat1.SetVal(1,1, 1.0);
  // create scaling repetitively
  auto ts = high_resolution_clock::now();

  const int NUMS=2;
  double valSum = 0.0;
  for(int i=0; i<NUMS; ++i)
  {
    ECMatrix mat2 ( mat1.Scale(i) );
//    ECMatrix mat2 = std::move( mat1.Scale(i) );
//    ECMatrix mat2;
//    mat2  =  mat1.Scale(i);
    valSum += mat2.GetVal(1,1);
  }
  cout << "valSum: " << valSum << endl;
  auto te = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(te-ts);
  cout << "Elapsed time (microseconds): " << duration.count() << endl;
  return 0;
}


