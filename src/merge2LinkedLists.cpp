/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return(head1);
	else{
				struct node *n = (struct node *)malloc(sizeof(struct node)), *n3;
				n3 = n;
				struct node *n1 = head1, *n2 = head2;
				//storing values in n3 in ascending order checking values in n1 and n2
				while (n1&&n2){
					n3->next = (struct node *)malloc(sizeof(struct node));
					n3 = n3->next;
					if (n1->num < n2->num){
						n3->num = n1->num;
						n1 = n1->next;
					}
					else if (n1->num > n2->num){
						n3->num = n2->num;
						n2 = n2->next;
					}
					else{
						n3->num = n2->num;
						n3->next = (struct node *)malloc(sizeof(struct node));
						n3 = n3->next; n3->num = n2->num;
						n2 = n2->next; n1 = n1->next;
					}
				}
				//when there are elements in n1 that have not been traversed
				if (n1)
				{
					n3->next = (struct node *)malloc(sizeof(struct node));
					n3 = n3->next;
					n3->num = n1->num;
					n3->next = n1->next;
				}
				//when there are elements in n2 that have not been traversed
				else if (n2)
				{
					n3->next = (struct node *)malloc(sizeof(struct node));
					n3 = n3->next;
					n3->num = n2->num;
					n3->next = n2->next;
				}
				else
					n3->next = NULL;
				return(n->next);
			}
}