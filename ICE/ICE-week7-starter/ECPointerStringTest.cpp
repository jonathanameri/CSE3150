#include "ECPointerString.h"
#include <iostream>
#include <string>
using namespace std;

// test copy/move to self
void Test1()
{
  ECStringPtr sp("CSE 3150");
  sp = sp;
  cout << sp.GetString() << endl;

  ECStringPtr sp2  = std::move(sp);

  //sp = std::move( sp );
  cout << "sp: " << sp.GetString() << endl;
  cout << "sp2: " <<  sp2.GetString() << endl;

  sp.SetString("stuff");
  sp = std::move( sp );
  cout << "sp: " << sp.GetString() << endl;
}

// test copy efficiency
void Test2()
{
  const int SZ_STR = 100000;
  string str(SZ_STR, 'a');
  ECStringPtr sp(str);
  // do copies
  const int NUM_CP = 10000;
  for(int i=0; i<NUM_CP; ++i)
  {
    sp = sp;
  }
}

int main()
{
  string str1 = "abc";
  string str2 = "def";
  ECStringPtr sp(str1);
  cout << sp.GetString() << endl; 
  sp.SetString(str2);
  cout << sp.GetString() << endl; 

  // assignment
  ECStringPtr sp2 = sp;
  //sp2 = sp;
  cout << sp2.GetString() << endl;
exit(1);
  // get duplicate
  //ECStringPtr strDup = std::move( sp.Duplicate() );
//  ECStringPtr strDup = sp.Duplicate();
//  cout << "duplicate: " << strDup.GetString() << endl;

  Test1();
 // Test2();

  return 0;
}

