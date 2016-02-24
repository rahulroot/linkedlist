#include <stdio.h>
#include <stdlib.h>
#include "ListNode.hpp"
#include "LinkedList.hpp"

void createList(NODE *&head, int data)
{
	if(!head)
	{
		head = getNode(data);
	}
	else
	{
		NODE *cur = head;
		while(cur->next != NULL)
			cur = cur->next;
		NODE *tmp = getNode(data);
		cur->next = tmp;
		tmp->prev = cur; 
	}
}

void createSortedList(NODE *&head, int data)
{
	if(!head)
	{
		head = getNode(data);
	}
	else if( head->data > data)
	{
		NODE *tmp = getNode(data);
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	else
	{
		NODE *cur = head;
		while(cur->next != NULL && cur->next->data < data)
			cur = cur->next;
		NODE *tmp = getNode(data);
		tmp->next = cur->next;
		if(cur->next)
			cur->next->prev = tmp;
		cur->next = tmp;
		tmp->prev = cur;
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
	while(head != NULL)
	{
		printf("%d(%d) ", head->data, ++cnt);
		head = head->next;
	}
	printf("\n");
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
	if(!head)
		return NULL;
	else
	{
		int cnt = 0;
		while(head != NULL)
		{
			cnt++;
			if(cnt == index)
				return head;
			head = head->next;
		}
	}
}

NODE* getNthFromEnd(NODE *head, int inx)
{
}

NODE* getMiddle(NODE *head)
{
}

NODE* SearchAndDelete(NODE *&head, int data)
{
	if(!head)	return NULL;
	else if (head->data == data)
	{
		NODE *tmp = head;
		head = head->next;
		head->prev = NULL;
		return tmp;
	}
	else
	{
		NODE *cur = head;
		while(cur != NULL)
		{
			if(cur->data == data)
			{
				NODE *tmp = cur;
				cur->prev->next = cur->next;
				if(cur->next)
					cur->next->prev = cur->prev;
				return tmp;
			}
			cur = cur->next;
		}
	}
	return NULL;
}

int CountValue(NODE *head, int val)
{
	if(!head)
		return 0;
	int cnt = 0;
	NODE *cur = head;
	while(cur != NULL)
	{
		if(cur->data == val)
			cnt++;
		cur = cur->next;
	}
	return cnt;
}

NODE* reverse(NODE *head)
{
  NODE *new_head = NULL;
  while(head!=NULL)
  {
    int data =  head->data;
    NODE *tmp = head;
    head = head->next;
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    free(tmp);

		if(!new_head) {
      new_head = new_node;
 		}
    else
    {
      new_node->next = new_head;
      new_head->prev = new_node;
			new_head = new_node;
  	}
  }
  return new_head;
}
