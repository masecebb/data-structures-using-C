#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int count = 0;

struct data{
	char name[100];
} *table[SIZE];

struct data *create(char name[]){
	data *temp = (data*)malloc(sizeof(data));
	strcpy(temp->name, name);
	return temp;
}

int hashFunction(char name[]){
	int key = 0;
	
	for(int i = 0; i < strlen(name); i++){
		key += name[i];
	}
	return key % SIZE;
}

void insert(char name[]){
	if(count == SIZE){
		printf("Table is full\n");
	}
	
	data *temp = create(name);
	int key = hashFunction(name);
	
	if(table[key] == NULL){
		table[key] = temp;
		count++;
		return;
	}else{
		while(table[key] != NULL){
			key = (key+1)%SIZE;
		}	
		table[key] = temp;
		count++;
		return;
	}
	
}

void search(char find[]){
	if(count == 0){
		printf("Table is empty\n");
		return;
	}
	for(int i = 0; i < SIZE; i++){
		if(table[i] != NULL && strcmp(table[i]->name, find) == 0){
			printf("%s is found at index %d\n", find, i+1);
			return;
		}
	}
	printf("%s is not available in the table!\n", find);
	return;
}

int deletionSearch(char find[]){
	int cek = 0;
	if(count == 0){
		return -1;
	}
	for(int i = 0; i < SIZE; i++){
		if(table[i] != NULL && strcmp(table[i]->name, find) ==0){
			return i;
		}
	}
	return 0;
}

void pop(char remove[]){
	int available = deletionSearch(remove);
	if(available == 0){
		printf("%s does not exist in the table\n", remove);
		return;
	}else if(available == -1){
		printf("Table empty\n");
		return;
	}else{
		free(table[available]);
		table[available] = NULL;
		count--;
		return;
	}
}

void print(){
	for(int i = 0; i < SIZE; i++){
		printf("%d. ", i+1);
		if(table[i] == NULL){
			printf("NULL\n");
		}else{
			printf("%s\n", table[i]->name);
		}
	}
}

int main(){
	insert("Petrus");
	insert("Andreas");
	insert("Yakobus");
	insert("Yohanes");
	insert("Filipus");
	insert("Bartolomeus");
	insert("Tomas");
	insert("Matius");
	insert("Tadeus");
	insert("Yudas");
	search("Petrus");
	pop("Yohanes");
	print();
	
	return 0;
}