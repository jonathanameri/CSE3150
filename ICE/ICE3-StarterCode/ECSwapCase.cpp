// Starter code
#include <string>
#include <iostream>

std::string ECSwapCase(std::string str)
{
  std::string res;
  for (int i = 0; i < str.size(); i++){
    if (islower(str[i])){
      res+=toupper(str[i]);
    }
    else{
      res+=tolower(str[i]);
    }
  }
  return res;
}

