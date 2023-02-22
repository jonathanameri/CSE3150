#include "ECList.h"
#include <iostream>
using namespace std;

int main()
{
  ECList list;
  list.Insert(3, NULL);
  list.Insert(1, NULL);
  list.Insert(2, NULL);

  // list has 2, 1, 3
  cout << "Number of nodes: " << list.GetSize() << endl;

  // delete
  ECListNode *pn = list.GetNode(1);
  list.Delete(pn);

  // list has 2, 3
  cout << "Number of nodes: " << list.GetSize() << endl;

  return 0;
}
