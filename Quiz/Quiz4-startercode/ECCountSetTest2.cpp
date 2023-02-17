// test if your code is efficient...
#include <set>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

#include "ECCountSet.cpp"

int main()
{
  set<int> ss;
  int SZ_TEST = 1000000;
  for(int i=0; i<SZ_TEST; ++i)
  {
    ss.insert(i);
  }
  auto start = high_resolution_clock::now();
  int NUM_ITER = 100;
  int cntMax = 0;
  for(int i=0; i<NUM_ITER; ++i)
  {
    int cnt = ECCountSet(ss, 3, 9);
    if( cnt > cntMax )
    {
      cntMax = cnt;
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  // should be 7; 
  cout << cntMax << endl;
  // my code finishes in less than 40 on MacBook Pro, 2.2 GHz
  // how about your code?
  cout << "Time: " << duration.count() << endl;
}

