#include "ECClass.h"
#include <iostream>
using namespace std;

int main()
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

  return 0;
}

