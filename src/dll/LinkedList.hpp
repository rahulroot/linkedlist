#ifndef __LINKEDLIST_HPP_
#define __LINKEDLIST_HPP_

#include "ListNode.hpp"

void createList(NODE *&head, int data);
void createSortedList(NODE *&head, int data);
void deleteList(NODE *&head);
void printList(NODE *head);
NODE* getMiddle(NODE *head);
int listSize(NODE *head);
NODE* SearchAndDelete(NODE *&head, int data);
int CountValue(NODE *list, int val);
NODE* reverse(NODE *head);

#endif
