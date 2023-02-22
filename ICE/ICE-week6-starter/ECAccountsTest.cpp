// Test ECAccounts
#include <vector>
#include <set>
#include <iostream>
using namespace std;

#include "ECAccounts.h"

static void Test1()
{
  ECAccount a1(123, "Joe"), a2(345, "Mike");
  vector<ECAccount> list;
  list.push_back(a1);
  list.push_back(a2);
  cout << "size: " << list.size() << endl;
  cout << "Account 1: " << list[0].GetAccountNum() << ", name: " << list[0].GetHolderName() << endl;
}
#if 0
static void Test2()
{
  ECAccount a1(123, "Joe"), a2(345, "Mike");
  set<ECAccount> list;
  list.insert(a1);
  list.insert(a2);
  cout << "size: " << list.size() << endl;
}
#endif

int main()
{
  Test1();
//  Test2();
}


