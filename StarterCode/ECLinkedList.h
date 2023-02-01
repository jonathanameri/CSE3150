#ifndef EC_LINKEDLIST_H
#define EC_LINKEDLIST_H

/*
 * This exercise tests your ability to deal with pointers and handle basic programming logic
 * Note: complex programs build on simple code like what you will be writing here
 * It is critical to be able to write and debug this kind of code
 */

/* Define a (single) linked list node, which stores an integer */
struct ECLinkedListNode
{
  int value;                /* value held by the linked list */
  struct ECLinkedListNode *pNext;    /* pointer to the next node */ 
};

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength( struct ECLinkedListNode *pHead );

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val);

#endif
