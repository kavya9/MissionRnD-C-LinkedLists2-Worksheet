/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	struct node *current1, *current2, *temp;
	if (head1->num < head2->num)
	{
		current1 = head1;
		current2 = head2;
	}
	else
	{
		current1 = head2;
		current2 = head1;
		temp = head1;
		head1 = head2;
		head2 = temp;
	}
	while (current1->next != NULL && current2 != NULL)
	{
		if (current2->num >= current1->num && current2->num <= current1->next->num)
		{
			head2 = head2->next;
			current2->next = current1->next;
			current1->next = current2;
			current2 = head2;
			current1 = current1->next;
		}
		else
			current1 = current1->next;
	}
	if (head2 != NULL)
		current1->next = head2;
	return head1;
}
