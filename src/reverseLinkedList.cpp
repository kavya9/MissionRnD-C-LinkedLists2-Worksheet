/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *temp,*current = head;
	if (current == NULL)
		return head;
	if (current->next == NULL)
	{
		head = current;
		return head;
	}
	temp = reverseLinkedList(current->next);
	current->next->next = current;
	current->next = NULL;
	return temp;
}
