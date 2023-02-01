#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
  /* your code here */
  if (pHead == NULL) return 0;
  int count = 1;
  struct ECLinkedListNode* curNode = pHead;
  while (curNode->pNext != NULL){
    count++;
    curNode = curNode->pNext;
  }
  return count;
}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val)
{
  /* your code here */
  if (pHead == NULL) return NULL;
  struct ECLinkedListNode* newHead = pHead;
  struct ECLinkedListNode* curNode;
  while(newHead->pNext != NULL && newHead->value == val){
    newHead = newHead->pNext;
  }
  curNode = newHead;
  while(curNode->pNext != NULL){
    //if delete
    if (curNode->pNext->value == val){
      if(curNode->pNext->pNext != NULL){
        curNode->pNext = curNode->pNext->pNext;
      }
      else{
        curNode->pNext = NULL;
        return newHead;
      }
    }
    curNode = curNode->pNext;
  }
  //If we are left with 1/2 node
  if(curNode->value == val){
    // return NULL;
    return NULL;
  }

  return newHead;
}
