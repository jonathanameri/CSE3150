#include <iostream>
#include "ECArrayofStrings.h" 

using namespace std;

ECArrayofStrings :: ECArrayofStrings() {}

ECArrayofStrings :: ~ECArrayofStrings() {}

void ECArrayofStrings :: AddString(const std::string &strToAdd )
{
  stringArray.push_back(strToAdd);
}

int ECArrayofStrings :: GetNumofStrings() const
{
  return stringArray.size();
}

int ECArrayofStrings :: GetMaxLen() const
{
  int maxLen = 0;
  for (auto k : stringArray)
  {
    if (k.length() > maxLen)
    {
      maxLen = k.length();
    }
  }
  return maxLen;
}


string ECArrayofStrings:: GetLongestCommonPrefixOfTwo(string a, string b) const
{
  string prefix = "";
  int i = 0;
  while (i < a.length() && i < b.length())
  {
    if (a[i] == b[i])
    {
      prefix += a[i];
    }
    else
    {
      break;
    }
    i++;
  }
  return prefix;
}


string ECArrayofStrings :: GetLongestCommonPrefix() const
{
  string prefix = "";
  if (stringArray.size() > 0)
  {
    prefix = stringArray[0];
    for (int i = 1; i < stringArray.size(); i++)
    {
      prefix = GetLongestCommonPrefixOfTwo(prefix, stringArray[i]);
    }
  }
  return prefix;
}

string ECArrayofStrings :: Concatnate() const
{
  string cat = "";
  for(auto s : stringArray)
  {
    cat += s;
  }
  return cat;
}

void ECArrayofStrings:: Dump() const
{
  for(auto s : stringArray)
  {
    cout << s << endl;
  }
}
