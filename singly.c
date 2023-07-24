#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node* addNewNode(int value){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	temp->value = value;
	return temp;
}

void printList(Node* root){
	for(Node *curr = root; curr != NULL; curr = curr->next ){
		printf("%d", curr->value);
	}
	printf("\n");
}

int main(void){
	Node* root = addNewNode(0);
	root->next = addNewNode(1);
	root->next->next = addNewNode(2);

	printList(root);

	return 0;	
}
