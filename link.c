#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int addnode(int data, struct linked_node **head) {
	struct linked_node *tmp = malloc(sizeof(struct linked_node));
	if (!tmp) return -1;

	tmp -> data = data;
	tmp -> next = *head;
	*head = tmp;

	return 0;
}
void show_list(struct linked_node *head) {
	if (head) {	
		printf("%d ", head -> data);	
		show_list(head -> next);
	}
	/*while (head) {
		printf("%d ", head -> data);
		head = head -> next;	
	}*/
	//printf("\n");
}
int addnodetail(int data, struct linked_node **head) {
	struct linked_node *tmp = malloc(sizeof(struct linked_node));
	struct linked_node *curr = *head;

	if (!tmp) return -1;

	tmp -> data = data;
	tmp -> next = NULL;
	
	if (!curr) 
		*head = tmp;
	else {
		while (curr -> next) curr = curr -> next;
		curr -> next = tmp;
	}	
	return 0;
}

int main() {
	struct linked_node *head = NULL;
	int val = -1;
	while (val) {
		printf("Enter value: ");
		scanf("%d", &val);
		addnode(val, &head);
		//printf("New head @ %p\n", head);
	}
	show_list(head);
	printf("\n");
	val = -1;
	while (val) {
		printf("Enter value to tail: ");
		scanf("%d", &val);
		addnodetail(val, &head);
	}
	show_list(head);
	printf("\n");

	return 0;
}
