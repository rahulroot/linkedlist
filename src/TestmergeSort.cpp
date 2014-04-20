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

	NODE *head1, *head2;
	head1 = head2 = NULL;

  for(int i = 0; i < maxnum; ++i)
    createSortedList(head1, a[i]);

  cout <<"Creating sorted list 1..." << endl;
	printList(head1);

  for(int i = maxnum-1; i >= 0; --i)
    createSortedList(head2, a[i]);

  cout <<"Creating sorted list 2..." << endl;
	printList(head2);


  cout <<"Merging 2 sorted list ..| ";
  NODE *head3 = mergeSort(head1, head2);
  printList(head3);

	cout <<"Deleting merged List." << endl;
	deleteList(head3);

  /* deleting original array */
  delete [] a;
  return 0;
}

