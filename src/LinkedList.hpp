#ifndef __LINKEDLIST_HPP_
#define __LINKEDLIST_HPP_

#include "ListNode.hpp"

/* Implementing Stack functionality using Linked list */
void pushFront(NODE *&head, int data);

/* function to remove the node from head of list
 * head pointer moves to next node in list
 */
NODE* popFront(NODE *&head);

/* add a tmp node at the tail of list */
void pushBackNode(NODE *&head, NODE *tmp);

/* function to create a list */
void createList(NODE *&head, int data);

/* function to create a sorted list */
void createSortedList(NODE *&head, int data);

/* function to delete the list */
void deleteList(NODE *&head);

/* function to print the list */
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

/* function to perform the merge sort on sorted list */
NODE* mergeSort(NODE *&list1, NODE *&list2);

/* get Nth node from the head of list */
NODE* getNth(NODE *head, int index);

/* get Nth node from the tail of list */
NODE* getNthFromEnd(NODE *head, int index);

/* get the middle node of list */
NODE* getMiddle(NODE *head);

/* return the size of list */
int listSize(NODE *head);

/* delete a node given it's pointer and list head */
void deletePtr(NODE *&head, NODE *ptr);

#endif
