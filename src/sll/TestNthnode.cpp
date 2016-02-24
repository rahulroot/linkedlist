#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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

	NODE *head = NULL;
  for(int i = 0; i < maxnum; ++i)
    createList(head, a[i]);

  cout <<"After Creating List..." << endl;
	printList(head);

  int sz = listSize(head);
	cout <<"Size of list : " << sz << endl; 
  NODE *tmp = getNth(head, 1);
  if(tmp)
    cout <<"1st node : " << tmp->data << endl;
  else
    cout <<"Ist node : NULL" << endl;

  tmp = getNth(head, sz/2);
  if(tmp)
    cout <<"middle node : " << tmp->data << endl;
  else
    cout <<"middle node : NULL" << endl;

  tmp = getNth(head, sz);
  if(tmp)
    cout << sz <<" node : " << tmp->data << endl;
  else
    cout << sz <<" node : NULL" << endl;

  cout <<"-----------"<< endl;
  tmp = getNthFromEnd(head, 1);
  if(tmp)
    cout <<"1st node from end : " << tmp->data << endl;
  else
    cout <<"Ist node from end : NULL" << endl;

  tmp = getNthFromEnd(head, sz/2);
  if(tmp)
    cout <<"middle node from end : " << tmp->data << endl;
  else
    cout <<"middle node from end : NULL" << endl;

  tmp = getNthFromEnd(head, sz);
  if(tmp)
    cout << sz <<" node : " << tmp->data << endl;
  else
    cout << sz <<" node : NULL" << endl;

  tmp = getMiddle(head);
  if(tmp)
    cout <<"Middle node is : " << tmp->data << endl;
  else
    cout <<"Middle node is : NULL" << endl;

	cout <<"Deleting list." << endl;
	deleteList(head);

  delete [] a;
  return 0;
}

