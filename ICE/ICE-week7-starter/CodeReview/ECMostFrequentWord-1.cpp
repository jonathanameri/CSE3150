#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

string ECMostFrequentWord(const string &strText)
{
  unordered_map<string, int> freqWords;
  string currWord = "";
  string res;

  // Iterates across each char in the string, adding it to a string to make up a full word until it gets to a non alphanumerical number
  for (auto &c : strText) {
    // When at a non alphanumerical number, take this word and add it to the set of words
    if ( !isalnum(c) ) {
      // Skips empty strings, specifically if we have a case where multiple non-alnum chars are in sequence (?)
      if (currWord == "")
        continue;
        
      // Tries to find the word, if it can't, it adds it to the set. Otherwise it increases the count of the word      
      auto freqWord = freqWords.find(currWord);
      if ( freqWord == freqWords.end() ) 
        freqWords.insert({currWord, 1});
      else
        (*freqWord).second += 1;
      
      currWord = "";
    } else
      // If char is alnum, keep appending it to the full word string
      currWord += c;
  }

  // Do the inner loop one last time for the last char in the string
  if ( currWord != "") {
    auto freqWord = freqWords.find(currWord);
    if ( freqWord == freqWords.end() ) 
        freqWords.insert({currWord, 1});
    else {
      (*freqWord).second += 1;
      currWord = "";
    }
  }

  // Iterate across the set of all unique words, finding the one with the max frequency. If two are equal, get the one that alphabetically 'less'
  int maxCount = 0;
  for (auto freqWord : freqWords) {
    if ( freqWord.second > maxCount ) {
      res = freqWord.first;
      maxCount = freqWord.second;
    }
    else if ( freqWord.second == maxCount )
      res = res.compare(freqWord.first) < 0 ? res : freqWord.first;
  }

  return res;
}

