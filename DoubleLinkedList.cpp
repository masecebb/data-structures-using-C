#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int value;
	char str[100];
	struct Node *next;
	struct Node *prev;
} *head = NULL, *tail = NULL;

int pushEmpty(Node *newNode){
	if(head == NULL){
		head = tail = newNode;
	}
	return 0;
}

Node *createNewNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void pushHead(int value){
	Node *newNode = createNewNode(value);
	if(pushEmpty(newNode)== 0){
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
}

void printAll(){
	Node *curr = head;
	if(head == NULL){
		puts("kosong");
	}else{
		while(curr){
			printf("%d -> ", curr->value);
			curr = curr->next;
		}
		return;
	}
}

void pushTail(int value){
	Node *newNode = createNewNode(value);
	if(pushEmpty(newNode)== 0){
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		return;
	}
}

void pushMid(int value){
	Node *newNode = createNewNode(value);
	if(pushEmpty(newNode)== 1){
		return;
	}
	if(value >= head->value){
		pushHead(value);
	}
	if(value <= tail->value){
		pushTail(value);
	}
	else{
		Node *curr = head;
		while(curr->next->value > value && curr->next != NULL){
			curr = curr->next;
		}
		newNode->prev = curr;
		newNode->next = curr->next;
		curr->next = newNode;
		newNode->next->prev = newNode;
	}
}

void popHead(){
	if(head == NULL){
		puts("kosong");
		return;
	}else{
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			Node *toPop = head;
			head = head->next;
			free(toPop);
			head->prev = NULL;
		}
	}
}

void popTail(){
	if(tail == NULL){
		puts("kosong");
		return;
	}else{
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			Node *toPop = tail;
			tail = tail->prev;
			free(toPop);
			tail->next = NULL;
		}
	}
}

void popMid(int value){
	if(head == NULL){
		puts("kosong");
		return;
	}
	if(head->value == value){
		popHead();
	}else if(tail->value == value){
		popTail();
	}else{
		Node *curr = head;
		while(curr){
			if(curr->value == value){
				break;
			}
			curr = curr->next;
		}
		Node *nextNode = curr->next;
		Node *prevNode = curr->prev;
		nextNode->prev = prevNode;
		prevNode->next = nextNode; 
		free(curr);
		curr = NULL;
	}
}

int main(){
	pushMid(10);
	pushHead(9);
	pushTail(11);
	pushMid(2);
	printAll();
	return 0;
}