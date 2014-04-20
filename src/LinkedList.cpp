#include <stdio.h>
#include "ListNode.hpp"
#include "LinkedList.hpp"
#include <assert.h>

void pushFront(NODE *&head, int data)
{
	NODE *tmp = getNode(data);
	if(!head)
	{
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}

NODE* popFront(NODE *&head)
{
  if(!head)
    return NULL;
  NODE *tmp = head;
  head = head->next;
  return tmp;
}


void pushBackNode(NODE *&head, NODE *tmp)
{
  if(!head)
    head = tmp;
  else
  {
    NODE *cur = head;
    while(cur->next != NULL)
      cur = cur->next;
    cur->next = tmp;
  }
  tmp->next = NULL;
}

void createList(NODE *&head, int data)
{
	if(!head)
	{
		head = getNode(data);
	}
	else
	{
		NODE *cur = head;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = getNode(data);
	}
}

void deleteList(NODE *&head)
{
	while(head != NULL)
	{
		NODE *tmp = head;
		head = head->next;
		deleteNode(tmp);
	}
	head = NULL;
}

void printList(NODE *head)
{
	int cnt = 0;
	printf("List Data(Index)\n");
	while(head != NULL)
	{
		printf("%d(%d) ", head->data, ++cnt);
		head = head->next;
	}
	printf("\n");
}

void removeAltNode(NODE *&list1, NODE *&list2)
{

	assert(list1 != NULL && list2 == NULL);
	int i = 1;
	NODE *cur = list1;
	NODE *prev = NULL;

	while(cur!= NULL)
	{
		if (i%2==0)
		{
			NODE *tmp = prev->next;
			prev->next = cur->next;
			pushFront(list2, tmp->data);
			deleteNode(tmp);
		}
		else
			prev = cur;
		cur = cur->next;
		i++;
	}
}

void joinList(NODE *&list1, NODE *&list2)
{

	assert(list1 != NULL && list2 != NULL);
	NODE *tmp = list1;
	while(tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = list2;
	list2 = NULL;
}

NODE* mergeSort(NODE *&list1, NODE *&list2)
{
  NODE *list3 = NULL;
  NODE *tmp = NULL;
  while(list1 && list2)
  {
    tmp = NULL;
    if( list1->data <= list2->data)
    {
      tmp = popFront(list1);
      pushBackNode(list3, tmp);
    }
    else
    {
      tmp = popFront(list2);
      pushBackNode(list3, tmp);
    }
  }

  tmp = NULL;
  while(list1)
  {
    tmp = popFront(list1);
    pushBackNode(list3, tmp);
  }

  tmp = NULL;
  while(list2)
  {
    tmp = popFront(list2);
    pushBackNode(list3, tmp);
  }

  return list3;
}

void createSortedList(NODE *&head, int data)
{
  if(!head)
  {
    head = getNode(data);
  }
  else if (head->data > data)
  {
    NODE *tmp = getNode(data);
    tmp->next = head;
    head = tmp;
  }
  else
  {
    NODE *cur = head;
    while(cur->next != NULL && cur->next->data < data)
      cur = cur->next;
    NODE *tmp = getNode(data);
    tmp->next = cur->next;
    cur->next = tmp;
  }
}

int listSize(NODE *head)
{
  int cnt = 0;
  while(head != NULL)
  {
    head = head->next;
    cnt++;
  }
  return cnt;
}


NODE* getNth(NODE *head, int index)
{
  if(index > listSize(head))
    return NULL;

  int count = 0;
  while(head != NULL)
  {
    count++;
    if(count == index)
      return head;
    head = head->next;
  }
}

NODE* getNthFromEnd(NODE *head, int inx)
{
  NODE *slow, *fast;
  slow = fast = head;
  if(inx > listSize(head))
    return NULL;
  while(inx--)
    fast = fast->next;
  while(fast!=NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

NODE* getMiddle(NODE *head)
{
  if(!head)
    return NULL;
  if(head->next == NULL)
    return NULL;
  if(head->next->next == NULL)
    return head;

  NODE *slw, *fst;
  slw = fst = head;
  while(fst!=NULL)
  {
    fst = fst->next;
    if(fst)
    {
      fst = fst->next;
      slw = slw->next;
    }
  }
  return slw;
}

void deletePtr(NODE *&head, NODE *ptr)
{
	if (!head)  return; /* if there is no list */

  if ( head == ptr) /* if list has one node or ptr point to first node in the list */
  {
    NODE *tmp = head->next;
    deleteNode(head);
    head = tmp;
    return;
  }

  NODE *cur = head;
  NODE *prev = head;
  while ( cur != NULL && cur != ptr) /* search for this node pointer */
  {
    prev = cur;
    cur = cur->next;
  }

  if (!cur) return; /* we didn't find the pointer in the list while traversing the list */

  if ( ! cur->next ) /* ptr point to last node of the list */
  {
    prev->next = cur->next;
    deleteNode(cur);
    return;
  }

  /* any other inter-mediatory node */
  {
    int tmp = ptr->data;    /* swap the value of ptr with ptr->next->data */
    ptr->data = ptr->next->data;
    ptr->next->data = tmp;
  }

  NODE *tmp = ptr->next;
  ptr->next = ptr->next->next;
  deleteNode(tmp);
  return;

}

void printListInReverse(NODE *head)
{
	static int cnt = 0;
  if(!head)
    return;
	cnt++;
  printListInReverse(head->next);
  printf("%d(%d) ", head->data, cnt);
	cnt--;
	if (!cnt)
		printf("\n");
}

NODE* revList(NODE *parent, NODE *current)
{
  NODE *revHead = NULL;
  if ( current == NULL )
    revHead = parent;
  else
  {
    revHead = revList(current, current->next);
    /* current become revHead, current->next will be assigned to parent */
    current->next = parent;
  }
  return revHead;
}
