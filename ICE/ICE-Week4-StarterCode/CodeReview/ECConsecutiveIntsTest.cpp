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
exit(1);
  // test long
  string xyz = "";
  for(int i=0; i<1000; ++i)
  {
    xyz += std::to_string(i);
  }
  bool ff = ECConsecutiveInts(xyz);
   if(ff)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
  // NON-secontucive 
  xyz += "00";
cout << "xyz: " << xyz << endl;
  ff = ECConsecutiveInts(xyz);
   if(ff)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  } 
#if 0
  // NOT consecutive
  string d1 = "0-10000";
  bool fd1 = ECConsecutiveInts(d1);
  if(fd1)
  {
    cout << "Consecutive\n";
  }
  else
  {
    cout << "NOT Consecutive\n";
  }
#endif
}

