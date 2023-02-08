//#include "ECLongestPrefix.h" 
#include <iostream>
#include <string.h>

using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...
  if(numStrings == 0){
    return "";
  }
  if(numStrings == 1){
    return arrayStrings[0];
  }

  int res = arrayStrings[0].length();

  for(int i = 1; i < numStrings; i++){
    int strindex = 0;
    while(arrayStrings[i][strindex] == arrayStrings[0][strindex]){
      strindex++;
    }
    res = min(strindex, res);
  }

  return arrayStrings[0].substr(0, res);
  
  }

