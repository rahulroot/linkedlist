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

  NODE *head;
  head = NULL;

  for(int i = 0; i < maxnum; ++i)
    createSortedList(head, a[i]);

  cout <<"Creating sorted list 1..." << endl;
  printList(head);

  cout <<"Removing duplicate from sorted list." << endl;
  RemoveDuplicateFromSortedList(head);
  printList(head);

  cout <<"Deleting List." << endl;
  deleteList(head);

  head = NULL;
	
  for(int i = 0; i < maxnum; ++i)
    createList(head, a[i]);

  cout <<"Creating list 1..." << endl;
  printList(head);

  cout <<"Removing duplicate from list." << endl;
  RemoveDuplicateFromUnsortedList(head);
  printList(head);

  cout <<"Deleting List." << endl;
  deleteList(head);

  /* deleting original array */
  delete [] a;
  return 0;
}

