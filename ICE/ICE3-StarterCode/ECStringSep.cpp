// Starter code
#include <iostream>

using namespace std;

string ECStringSep(const string &str)
{
  string res = "";
  for (int i = 0; i < (int)str.length()-1; i++){
    res+=str[i];
    res+=',';
  }
  if(str.length() > 0){
    res+=str[str.length()-1];
  }
  return res;
}

