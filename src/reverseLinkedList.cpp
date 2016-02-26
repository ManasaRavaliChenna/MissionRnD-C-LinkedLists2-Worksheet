/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head){
		struct node *prev = NULL, *nex, *pres = head;
		while (pres != NULL)
		{
			nex = pres->next;
			pres->next = prev;
			prev = pres;
			pres = nex;
		}
		return prev;
	}
	return NULL;
}