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

	NODE *head = NULL;
  for(int i = 0; i < maxnum; ++i)
    createList(head, a[i]);

  cout <<"After Creating List..." << endl;
	printList(head);

	cout <<"Deleting 1st Ptr: "; deletePtr(head, head);
  printList(head);
  cout <<"Deleting 2nd Ptr: " ; deletePtr(head, getNth(head, 2));
  printList(head);
  cout <<"Deleting middle Ptr: " ; deletePtr(head, getNth(head,listSize(head)/2));
  printList(head);
  cout <<"Deleting 2ndLast Ptr: " ; deletePtr(head, getNth(head, listSize(head)-1));
  printList(head);
  cout <<"Deleting Last Ptr: " ; deletePtr(head, getNth(head, listSize(head)));
  printList(head);

	cout <<"Deleting list." << endl;
	deleteList(head);

  delete [] a;
  return 0;
}

