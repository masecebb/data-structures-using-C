#include <stdio.h>
#include <stdlib.h>

struct Tree{
	int num;
	Tree *left, *right;
};

Tree *parent;

Tree *createNode(int num){
	Tree *node = (Tree*)malloc(sizeof(Tree));
	node->num = num;
	node->left = node->right = NULL; 
	
	return node;
}

Tree *push(Tree *parent, int num){
	if(parent == NULL){
		return createNode(num);
	}else if(num < parent->num){
		parent->left = push(parent->left, num);
	}else if(num > parent->num){
		parent->right = push(parent->right, num);	
	}
	return parent;
}

void inOrder(Tree *curr){
	if(curr != NULL){
		inOrder(curr->left);
		printf("%d ", curr->num);
		inOrder(curr->right);
	}
}

void preOrder(Tree *curr){
	if(curr != NULL){
		printf("%d ", curr->num);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void postOrder(Tree *curr){
	if(curr != NULL){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ", curr->num);
	}
}

int main(){
	parent = push(parent, 100);
	parent = push(parent, 50);
	parent = push(parent, 30);
	parent = push(parent, 150);
	
//	puts("");
	printf("Inorder: \n");
	inOrder(parent);
	puts("");
	printf("Preorder: \n");
	preOrder(parent);
	puts("");
	printf("Postorder: \n");
	postOrder(parent);
	
	return 0;
}