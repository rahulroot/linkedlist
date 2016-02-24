#include <iostream>
#include <stdlib.h>
#include "LinkedList.hpp"
#include "ListNode.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if(argc < 2 )
  {
    cout <<"Usage : ./a.out no_of_records." << endl;
    cout <<"Usage : ./a.out 2000 " << endl;
    exit(-1);
  }

  int maxnum = atoi(argv[1]);
  int *a = new int[maxnum];
  if(!a) {
    cout <<" Insufficient Memory. " << endl;
    exit(-1);
  }

  int lb = 0, ub = maxnum - 1;
  for(int i = lb; i <= ub; ++i)
  {
    a[i] = rand()%maxnum;
  }

	cout <<"Generated Number Seq..." << endl;
  for(int i = 0; i < maxnum; ++i)
    cout << a[i] <<" ";
	cout << endl;

	NODE *list1, *list2;
	list1 = list2 = NULL;

  for(int i = 0; i < maxnum; ++i)
		createList(list1, a[i]);
  cout <<"List1 : ";
  printList(list1);

	createList(list2, 10);
  cout <<"List2 : ";
  printList(list2);

  list2->next = list1;
	cout << list2->data <<" --> " << list1->data << endl;

  NODE *tmp = NULL;
  if( (tmp = getIntersectNode(list1, list2))!=NULL)
    cout <<"Intersect point node is : "<< tmp->data << endl;
  else
    cout <<"NULL" << endl;
	list2->next = NULL;

  list2->next = list1->next;
	cout << list2->data <<" --> " << list1->next->data << endl;
  if( (tmp = getIntersectNode(list1, list2))!=NULL)
    cout <<"Intersect point node is : "<< tmp->data << endl;
  else
    cout <<"NULL" << endl;
	list2->next = NULL;

  list2->next = list1->next->next->next;
	cout << list2->data <<" --> " << list1->next->next->next->data << endl;
  if( (tmp = getIntersectNode(list1, list2))!=NULL)
    cout <<"Intersect point node is : "<< tmp->data << endl;
  else
    cout <<"NULL" << endl;
	list2->next = NULL;

	tmp = list1;
  while(tmp->next != NULL)
    tmp = tmp->next;

  list2->next = tmp;
	cout << list2->data <<" --> " << tmp->data << endl;
  if( (tmp = getIntersectNode(list1, list2))!=NULL)
    cout <<"Intersect point node is : "<< tmp->data << endl;
  else
    cout <<"NULL" << endl;
  list2->next = NULL;

  if( (tmp = getIntersectNode(list1, list2))!=NULL)
    cout <<"Intersect point node is : "<< tmp->data << endl;
  else
    cout <<"NULL" << endl;

	cout <<"Deleting list1." << endl;
  deleteList(list1);

	cout <<"Deleting list2." << endl;
  deleteList(list2);
  /* deleting original array */
  delete [] a;
  return 0;
}

