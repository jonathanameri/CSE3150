#ifndef _EC_LIST_H
#define _EC_LIST_H

class ECListNode;

// Linked list 
class ECList
{
public:
  ECList();
  
  // insert node with value val after a node
  // if node is NULL, insert to the front
  void Insert(int val, ECListNode *pPre);

  // delete a node. Do nothing if this node is not in the list
  void Delete(ECListNode *pNode);

  // get a node with value; if multiple nodes with the same value, return the first from head
  ECListNode *GetNode(int val);

  // get the number of nodes in the list
  int GetSize() const;

private:
  ECListNode *pHead;
  int numNodes;
};

#endif
