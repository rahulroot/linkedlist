#ifndef __LISTNODE_HPP_
#define __LISTNODE_HPP_

struct node 
{
	int data;
	struct node *next;
};

typedef struct node NODE;

NODE* getNode(int data);
void  deleteNode(NODE *ptr);

#endif
