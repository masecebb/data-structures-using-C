#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	int value;
	data *next;
} *head = NULL, *tail = NULL;

data *createNewNode(int value){
	data *newNode = (data*)malloc(sizeof(data));
	newNode->value = value;
	newNode->next = NULL;
	
	return newNode;
}

void pushHead(int value){
	data *newNode = createNewNode(value);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int value){
	data *newNode = createNewNode(value);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}else{
		tail->next = newNode;
		tail = tail->next;
	}
}

void pushMid(int value){
	data *newNode = createNewNode(value);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}else if(head->value > value){
		pushHead(value);
	}else if(tail->value < value){
		pushTail(value);
	}else{
		data *curr = head; // start checking from head
		while(curr->next != NULL && curr->next->value < value){
			curr = curr->next;
		}
		data *afterNewNode = curr->next;
		beforeNewNode->next = newNode;
		newNode->next = afterNewNode;
		
	}
}

void printNodes(){
	data *curr = head;
	while(curr != NULL){
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

void popHead(){
	//no data inside the linked list
	if(head == NULL){
		return;
	}else{
		data *temp = head;
		head = head->next;
		free(temp);
	}
}

void popTail(){
	if(head == NULL){
		return;
	}else{
		data *curr = head;
		while(curr->next != tail){
			curr = curr->next;
		}
		data *temp = tail;
		tail = curr;
		tail->next = NULL;
		free(temp);
	}
}

void popMid(int value){
	if(value == head->value){
		popHead();
	}else if(value == tail->value){
		popTail();
	}else{
		data *curr = head;
		while(curr->next != NULL && curr->next->value != value){
			curr = curr->next; 
		}
		if(curr->next != NULL && curr->value == value){
			data *temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}else{
			printf("Data's not found\n");
		}
	}
}


int main(){
	pushHead(9);
	printNodes();
	pushHead(7);
	printNodes();
	pushTail(10);
	printNodes();
	pushMid(8);
	pushMid(11);
	pushMid(20);
	pushMid(30);
	printNodes();
	popHead();
	printNodes();
	popTail();
	printNodes();
	popMid(10);
	printNodes();
	
	
	return 0;		
}