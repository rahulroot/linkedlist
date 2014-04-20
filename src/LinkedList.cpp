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
