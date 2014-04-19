#ifndef __LINKEDLIST_HPP_
#define __LINKEDLIST_HPP_

#include "ListNode.hpp"

/* Implementing Stack functionality using Linked list */
void pushFront(NODE *&head, int data);

void createList(NODE *&head, int data);
void deleteList(NODE *&head);
void printList(NODE *head);

/* This function take a list1 as initial list
 * remove the alternate node from list1
 * use add_front facility to populate list2 to maintain reverse order of list 
 * list2 must be NULL
 */
void removeAltNode(NODE *&list1, NODE *&list2);

/* join the list2 head into list1 tail to
 * create one list */
void joinList(NODE *&list1, NODE *&list2);

#endif
