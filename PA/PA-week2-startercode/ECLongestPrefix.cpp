#include "ECLongestPrefix.h" 
#include <iostream>

using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...
  string prefix = "";
  if (numStrings > 0){
    prefix = arrayStrings[0];

    for(int i=0; i<numStrings; ++i)
    {
      int n = prefix.size();
      for(int j = 0; j < arrayStrings[i].size(); j++){
        if (j > (n-1) || prefix[j] != arrayStrings[i][j]){
          prefix = prefix.substr(0,j);
        }
      }
      // cout << arrayStrings[i] << " ";
    }
}
  // cout << prefix << endl;


  return prefix;
}

