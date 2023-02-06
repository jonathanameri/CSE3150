//
//  ECConsecutiveInts.cpp
//  
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>
using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any seperators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on..
bool nextPow(int curNum){
  if(curNum == 0) return false;
  while(curNum > 0){
    if (curNum % 10 != 9){
      return false;
    }
    curNum = curNum/10;
  }
  return true;
}

bool ECConsecutiveInts(const string &strInput)
{
  if(strInput.length() == 0 ) return false;
  //First check if every character is a digit
  for(int d = 0; d < strInput.length(); d++){
    if (!isdigit(strInput[d])) return false;
  }
  int curLen = 1;
  int maxLen = 6;
  int curNum;
  int nextNum;
  bool res;
  bool inc;
  string str = strInput; //Compiler was complaining about the 'const' and this fixed it
  int n = str.length();
  
  while(curLen <= maxLen){
    int i = 0;
    res = true;
    inc = false;
    while(i < n){
   
      if(i+curLen <= n){
        curNum = stoi(str.substr(i,curLen)); //Get current number
        // cout << curNum << endl;
      }

      i = i+curLen; //Increment pointer to next number
      if(nextPow(curNum)){
        curLen++;
        inc = true;
      }
      // cout<< i << " " << curLen << " " << n << endl;
      if(i+curLen <= n){
        // cout<< "taking next num" << endl;
        nextNum = stoi(str.substr(i,curLen));
      }
      // cout << curNum << endl;
      // cout << nextNum << endl;
    
      if (nextNum - curNum != 1) {
        res = false;
        break;
      }
      else if (i + curLen == n){
        return true;
      }
      
    }
    if (res == true) return true;
    if(!inc) curLen++;
  }
  return false;
}

