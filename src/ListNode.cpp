#include "ListNode.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

NODE* getNode(int data)
{
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->next = NULL;
	tmp->data = data;
}

void deleteNode(NODE *tmp)
{
	if(tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}
