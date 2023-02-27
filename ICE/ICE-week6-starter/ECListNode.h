#ifndef _EC_LIST_NODE_H
#define _EC_LIST_NODE_H

#include <iostream>

// Class for linked list node
class ECListNode
{
public:
  ECListNode() : val(0), pNext(NULL) {}
  ECListNode *GetNext() const { return pNext; }
  void SetNext(ECListNode *pn) { pNext = pn;  }
  int GetValue() const { return val; }
  void SetValue(int v) { val = v; }

private:
  int val;
  ECListNode *pNext;
};

#endif
