#include "ECPointerString.h"
#include <iostream>
using namespace std;

ECStringPtr :: ECStringPtr() : ptr(NULL)
{
cout << "Default\n";
}

ECStringPtr:: ECStringPtr(const std::string &strInit)
{
  ptr = new string(strInit);
cout << "Custom\n";
}

ECStringPtr :: ECStringPtr(const ECStringPtr &rhs)
{
cout << "Copy\n";
  if( rhs.ptr != NULL )
  {
    ptr = new string( rhs.GetString() );
  }
  else
  {
    ptr = NULL;
  }
}

ECStringPtr :: ECStringPtr(ECStringPtr &&rhs)
{
cout << "Move\n";
  ptr = rhs.ptr;
  rhs.ptr = NULL;
}

ECStringPtr ::  ~ECStringPtr()
{
  delete ptr;
}
        
ECStringPtr &  ECStringPtr :: operator=(const ECStringPtr &rhs)
{
cout << "Assignment\n";
  if( rhs.ptr != NULL )
  { 
    ptr = new string( rhs.GetString() );
  }
  else
  { 
    ptr = NULL;
  }
  return *this;
}

void ECStringPtr :: SetString(const std::string &strToSet)
{
  if( ptr != NULL )
  {
    delete ptr;
  }
  ptr = new string( strToSet );
}

//      const std::string *GetPtr() const;
std::string ECStringPtr :: GetString() const
{
  string str;
  if( ptr != NULL )
  {
    str = *ptr;
  }
  return str;
}

        // Skip for the first pass. Create a string by duplicating itself, e.g. if this string is "abc", 
        // the new string is "abcabc"
  //     ECStringPtr Duplicate() const;


