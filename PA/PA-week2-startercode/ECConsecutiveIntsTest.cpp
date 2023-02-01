// To build: c++ ECConsecutiveIntsTest.cpp ECConsecutiveInts.cpp -o test
#include <string>
#include <iostream>

using namespace std;

extern bool ECConsecutiveInts(const string &strInput);

int main()
{
  // Not consecutive
  string a = "1234578";
  bool fa = ECConsecutiveInts(a);
  if(fa)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
  // consecutive
  string b = "111213141516";
  bool fb = ECConsecutiveInts(b);
  if(fb)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
  // NOT consecutive
  string c = "123124125127";
  bool fc = ECConsecutiveInts(c);
  if(fc)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
  // NOT consecutive
  string d = "123a567";
  bool fd = ECConsecutiveInts(d);
  if(fd)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
}

