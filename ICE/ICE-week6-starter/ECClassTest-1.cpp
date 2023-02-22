#include "ECClass.h"
#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

void Test1()
{
  ECStudent s1("Mike");
  s1.SetHW(80.0);
  s1.SetMT(90);
  s1.SetFinal(70);
  ECStudent s2("Annie");
  s2.SetHW(90.0);
  s2.SetMT(95);
  s2.SetFinal(80);
  ECStudent s3("Alex");
  s3.SetHW(90.0);
  s3.SetMT(95);

  ECClass c0513;
  c0513.AddStudent(s1);
  c0513.AddStudent(s2);
  c0513.AddStudent(s3);
  double med = c0513.GetAveMedian();
  cout << "Median ave: " << med << endl;

  const int n = 0;
  string str = c0513.GetRankedStudentName(n);
  cout << "Student ranked at " << n << " is: "  << str << endl;
}

void Test2()
{
  // larger scale testing
  ECClass cse3150;
  int NUM_ADD = 10;
  int NUM_QUERY_PER_ADD = 1;
  for(int i=0; i<NUM_ADD; ++i)
  {
    string name="s" + std::to_string(i);
    ECStudent s1(name);
    s1.SetHW(i);
    s1.SetMT(i);
    s1.SetFinal(i);
    cse3150.AddStudent(s1);

    double medMax = 0.0;
    string stHigh;    
    for(int j=0; j<NUM_QUERY_PER_ADD; ++j)
    {
      // query
      double med = cse3150.GetAveMedian();
      //cout << "Median ave: " << med << endl;

      const int n = 0;
      string str = cse3150.GetRankedStudentName(n);
      //cout << "Student ranked at " << n << " is: "  << str << endl;

      if( medMax < med )
      {
        medMax = med;
        stHigh = str;
      }
    }

    cout << "Student: " << stHigh << ". MaxMed: " << medMax << endl;
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  Test1();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running time: "  << duration.count() << endl;
}


