#include <stdio.h>
#include <stdlib.h>

struct Data{
	int num;
	struct Data *left;
	struct Data *right;
}*root;

struct Data *insert(struct Data *node, int n){
	if(node == NULL){
		node = (struct Data*) malloc(sizeof(struct Data));
		node->number = n;
		node->left = node->right = NULL;
	}else if(n < node->number){
		node->left = insert(node->left, n);
	}else if(n > node->number){
		node->right = insert(node->right, n);
	}
	return node;
}

struct Data *delete(struct Data *node, int n){
	if(node == NULL){
		printf("Data not found\n");
		return NULL;
	}else{
		if(n < node->number){
			node->left = delete(node->left, n);
		}else if(n > node->number){
			node->right = delete(node->right, n);
		}else{
			if(node->left == NULL && node->right == NULL){
				free(node);
				node = NULL;
			}else if(node->left == NULL){
				struct Data *temp = node;
				node = node->right;
				free(temp);
				temp = NULL;
			}else if(node->right == NULL){
				struct Data *temp = node;
				node = node->left;
				free(temp);
				temp = NULL;
			}else{
				struct Data *temp = findMaxNode(node->left);
				node->number = temp->number;
				node->left = del(node->left, temp->number);
			}
		}
		return node;
	}
}

void inOrder(struct Data *curr){
	if(curr != NULL){
		inOrder(curr->left);
		printf("%d ", curr->number);
		inOrder(curr->right);
	}
}

void preOrder(struct Data *curr){
	if(curr != NULL){
		printf("%d ", curr->number);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void postOrder(struct Data *curr){
	if(curr != NULL){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ", curr->number);
	}	
}

int main(){
	
	return 0;
}