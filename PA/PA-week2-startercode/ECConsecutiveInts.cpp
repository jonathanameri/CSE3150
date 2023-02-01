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
bool nextPow(int i, int curLen, string &strInput){
  string curNum = strInput.substr(i,curLen);
  for(int j = 0; j < curNum.size(); j++){
    if (curNum[j] != '9') return false;
  }
  return true;
}

bool ECConsecutiveInts(const string &strInput)
{
  int curLen = 1;
  int maxLen = 6;
  int n = strInput.size();
  int curNum;
  int nextNum;
  bool res;
  bool inc;
  string str = strInput;
  while(curLen <= maxLen){
    int i = 0;
    res = true;
    while(i < n){
      inc = false;
      curNum = stoi(strInput.substr(i,curLen));
      if(nextPow(i,curLen,str)){
        curLen++;
        inc = true;
      }
      if(i+curLen < (n-1)){
        if(inc) {
          nextNum = stoi(strInput.substr(i+curLen-1,curLen));
        }
        else {
          nextNum = stoi(strInput.substr(i+curLen,curLen));
        }
        
      }
      if (nextNum - curNum != 1) {
        res = false;
        break;
      }
      i = i + curLen;
    }
    if (res == true) return true;
    curLen++;
  }
  return false;
}

