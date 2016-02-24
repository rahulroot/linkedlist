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

  cout <<"After Creating List..." << endl;
	NODE *head = NULL;
  for(int i = 0; i < maxnum; ++i)
    createList(head, a[i]);

	printList(head);
	deleteList(head);

	cout <<"Creating Sorted List..." << endl;
	for(int i = 0; i < maxnum; ++i)
		createSortedList(head, a[i]);

	printList(head);

#if 0

	cout <<"Testing SearchAndDelete Op.." << endl;
	NODE *tmp = SearchAndDelete(head, 1);
	if(tmp)
		cout << tmp->data <<" deleted." << endl;
	else
		cout <<"Not Found." << endl;
	deleteNode(tmp);
	printList(head);

	tmp = SearchAndDelete(head, 9);
	if(tmp)
		cout << tmp->data <<" deleted." << endl;
	else
		cout <<"Not Found." << endl;
	deleteNode(tmp);
	printList(head);

	tmp = SearchAndDelete(head, 5);
	if(tmp)
		cout << tmp->data <<" deleted." << endl;
	else
		cout <<"Not Found." << endl;
	deleteNode(tmp);
	printList(head);

	tmp = SearchAndDelete(head, 3);
	if(tmp)
		cout << tmp->data <<" deleted." << endl;
	else
		cout <<"Not Found." << endl;
	deleteNode(tmp);
	printList(head);

	tmp = SearchAndDelete(head, 8);
	if(tmp)
		cout << tmp->data <<" deleted." << endl;
	else
		cout <<"Not Found." << endl;
	deleteNode(tmp);
	printList(head);

	cout <<"Creating Sorted List..." << endl;
	for(int i = 0; i < maxnum; ++i)
		createSortedList(head, a[i]);
	printList(head);

	cout <<"Testing CountValue, count = " << CountValue(head, 3) << endl;
#endif

	NODE *rev_head = reverse(head);
	printList(rev_head);

	deleteList(head);

  delete [] a;
  return 0;
}

