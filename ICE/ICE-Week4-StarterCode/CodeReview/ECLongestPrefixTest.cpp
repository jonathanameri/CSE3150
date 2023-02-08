#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
extern string ECLongestPrefix(int numStrings, const string arrayStrings[]);

void Test()
{
  const int NUM_STRS = 100;
  const int LEN_STR = 50000;
  //const int LEN_STR = 5000;
  // initialize strings
  string arrStrs[NUM_STRS];
  for(int i=0; i<NUM_STRS; ++i)
  {
    for(int j=0; j<LEN_STR-1; ++j)
    {
      arrStrs[i] += 'a';
    }
    // make strings different
    arrStrs[i] += 'a' + i;
  }

  // time it
  auto start = high_resolution_clock::now();
  string strPref = ECLongestPrefix(NUM_STRS, arrStrs);
  cout << "Common prefix: " << strPref.size() << endl;
  // time it again
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running time: "  << duration.count() << endl;
}

int main()
{
  Test();
}

