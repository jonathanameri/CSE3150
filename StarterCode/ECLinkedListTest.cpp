/* to compile:  g++ ECLinkedList.cpp ECLinkedListTest.cpp  */
#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* Test: get length of linked list */
void Test1()
{
  struct ECLinkedListNode *p1, *p2, *p3;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p3 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 2;
  p2->pNext = p3;
  p3->value = 1;
  p3->pNext = NULL;

  /* should be 3 */
  printf("Length: %d\n", ECGetLinkedListLength(p1) );
}

/* Test: delete the middle node inside linked list */
void Test2()
{
  struct ECLinkedListNode *p1, *p2, *p3, *pres;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p3 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 2;
  p2->pNext = p3;
  p3->value = 1;
  p3->pNext = NULL;

  /* delete node with value 2 */
  pres = ECLinkedListDeleteVal(p1, 2);

  /* should be 2 */
  printf("Length: %d\n", ECGetLinkedListLength(pres) );
}

/* Test: delete nodes with no such value  */
void Test3()
{
  struct ECLinkedListNode *p1, *p2, *p3, *pres;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p3 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 2;
  p2->pNext = p3;
  p3->value = 1;
  p3->pNext = NULL;

  /* delete node with value 4 */
  pres = ECLinkedListDeleteVal(p1, 4);
  
  /* should be 3 */
  printf("Length: %d\n", ECGetLinkedListLength(pres) );
}

/* Test: delete the multiple nodes with one in the front of linked list */
void Test4()
{
  struct ECLinkedListNode *p1, *p2, *p3, *pres;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p3 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 2;
  p2->pNext = p3;
  p3->value = 1;
  p3->pNext = NULL;

  /* delete node with value 1 */
  pres = ECLinkedListDeleteVal(p1, 1);
  
  /* should be 1 */
  printf("Length: %d\n", ECGetLinkedListLength(pres) );
}

/* Test: delete all nodes of linked list */
void Test5()
{
  struct ECLinkedListNode *p1, *p2, *pres;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 1;
  p2->pNext = NULL;

  /* delete node with value 1, this should delete all nodes  */
  pres = ECLinkedListDeleteVal(p1, 1);
  
  /* should be 0 */
  printf("Length: %d\n", ECGetLinkedListLength(pres) );
}

/* Test: delete two frontal nodes with one more left  */
void Test6()
{
  struct ECLinkedListNode *p1, *p2, *p3, *pres;
  p1 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p2 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p3 = (struct ECLinkedListNode *)malloc(sizeof(struct ECLinkedListNode) );
  p1->value = 1;
  p1->pNext = p2;
  p2->value = 1;
  p2->pNext = p3;
  p3->value = 2;
  p3->pNext = NULL;

  /* delete node with value 1 */
  pres = ECLinkedListDeleteVal(p1, 1);

  /* should be 1 */
  printf("Length: %d\n", ECGetLinkedListLength(pres) );
}


int main()
{
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  return 0;
}

