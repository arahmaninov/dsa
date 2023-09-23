// Read numbers till EOF and print them from the last to first

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node* next;
} node;

int main() {
	node *head = NULL;
	node *temp;
	
	int t = 0;
	while ((scanf("%d", &t)) != EOF) {
		temp = malloc(sizeof(node));
		temp->data = t;
		temp->next = head;
		head = temp;
	}

	while (head != NULL) {
		printf("%d\n", head->data);
		temp = head->next;
		free(head);
		head = temp;
	}



	return 0;
}
