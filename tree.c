#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}Node;

Node* AllocNewNode(int value){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(Node* root){
	if(root == NULL) return;
	printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->value);
	inorder(root->right);
}

void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->value);
}

int main(void){
	Node* root = AllocNewNode(0);
	root->left = AllocNewNode(1);
	root->right = AllocNewNode(2);

	root->left->left = AllocNewNode(3);
	root->left->right = AllocNewNode(4);

	root->right->left = AllocNewNode(5);
	root->right->right = AllocNewNode(6);//규칙없이 막 넣을 수 밖에 없음
	
	preorder(root); printf("\n");
	inorder(root); printf("\n");
	postorder(root); printf("\n");

	return 0;
}
