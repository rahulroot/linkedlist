#include "ListNode.hpp"
#include <stdlib.h>

NODE* getNode(int data)
{
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->next = tmp->prev = NULL;
	tmp->data = data;
	return  tmp;
}

void deleteNode(NODE *tmp)
{

#if 0
	/* Resulting in Invalid Read/Write Error in Valgrind
 	 * in case of tmp == NULL */ 
	if(tmp)
		free(tmp);
  tmp->next = tmp->prev = NULL;
#endif
	
	if(tmp!=NULL)
	{
		tmp->next = tmp->prev = NULL;
		free(tmp);
		tmp = NULL;	
	}
}
