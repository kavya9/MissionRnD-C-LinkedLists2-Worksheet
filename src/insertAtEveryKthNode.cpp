/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (K <= 0 || head == NULL)return NULL;
	struct node *current = head, *temp;
	int count;
	count = 1;
	if (K == 1)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = K;
		temp->next = current->next;
		current->next = temp;
		current = current->next;
	}
	while (1)
	{
		if (current->next == NULL) break;
		current = current->next;
		count++;
		if (count%K == 0)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			temp->next = current->next;
			current->next = temp;
			current = current->next;
		}
	}
	return head;
}
