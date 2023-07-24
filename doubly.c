#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
}Node;

Node* addNewNode(int value){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->value = value;
	return temp;
}

void printReversedList(Node* node){
	for(Node *curr = node; curr !=NULL; curr = curr->prev)
		printf("%d ", curr->value);
	printf("\n");	
}

void printList(Node *root){
	for(Node *curr = root; curr != NULL; curr = curr->next)
		printf("%d ", curr->value);
	printf("\n");
}

void insertValue(Node *root, int value){	
	Node* p = root;
	while (p->next != NULL){
		p = p->next;
	}
 	p->next = addNewNode(value);
	p->next->prev = p;
}

int main(void){
	Node* root = addNewNode(0);
	insertValue(root, 1);
	insertValue(root, 2);

	printReversedList(root->next->next);
	printList(root);

	return 0;	
}
