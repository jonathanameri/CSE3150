#include <string>
using namespace std;

// ensure x is trimed to contain its prefix of length of 
// no more than five after the function call
void TrimString(string &x)
{
  string res;
  for(unsigned int i=0; i<5 && i<x.size(); ++i)
  {
    res += x[i];
  }
  x = res;
}
