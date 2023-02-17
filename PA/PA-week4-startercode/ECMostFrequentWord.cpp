// Created by Y. Wu, Jan 28, 2023
// Given a string, find the most frequent word; if there is a tie, choose alphabetically smallest
// Word: consecutive alphanumerical symbols; that is, treat all non-alphanumerical symbols as separators
// for example, for "I have bad dreams that have bad feelings", return "bad"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
// #include <bits/stdc++.h>
using namespace std;

string ECMostFrequentWord(const string &strText)
{
  // cout << "here" <<endl;
  int len = strText.length();
  if (len == 0){
    return "";
  }
  char strCp[len+1];
  for(int i = 0; i < len; i++){
    strCp[i] = strText[i];
  }
  strCp[len] = '\0';
  // cout << "here" <<endl;
  
  // strText.copy(strCp, len);
  // cout << "here" <<endl;
  //Replace all non alphabet characters with space
  for(int i = 0; i < len; i++){
    if(!isalnum(strCp[i]))
    {
      strCp[i] = ' ';
    }
  }
  // cout << "here" <<endl;
  stringstream s(strCp);

  map<string, int>FW;
  string curWord;
  while(s >> curWord)
  {
    FW[curWord]++;
  }

  int maxCount = 0;
  string assWord;
  for(auto m : FW)
  {
    if (m.second > maxCount){
      maxCount = m.second;
      assWord = m.first;
    }
  }
  return assWord;

}

