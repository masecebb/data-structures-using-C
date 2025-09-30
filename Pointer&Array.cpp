#include <stdio.h>

int main(){
	
	//Array 
	
//	int num[5] = {1,2,3,4,5};
//	printf("%d\n", num[1]);
//	scanf("%d", &num[1]);
//	for(int i = 0; i < 5; i++){
//		printf("\n%d ", num[i]);
//	}
	
//	char huruf[10] = {'B','R','Y','A','N'};
//	printf("%c\n", huruf[4]);
	
//	char string[5][20] = {"BECE", "HANCIL", "WEWEY", "PEPIN", "WILCAN"};
//	printf("%s\n", string[1]);
//	scanf("%s", string[1]);
//	for(int i = 0; i < 5; i++){
//		printf("\n%s ", string[i]);
//	}
	
//	printf("%c", string[0][3]);

	//2D Array
	int matrix[5][5] = {{1,2,3},
						{1,3,5}};
						
//	printf("%d", matrix[0][1]);
	
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j < 3; j++){
//			printf("%d ", matrix[i][j]);
//		}
//		printf("\n");
//	}
	
	//Pointer
//	int a = 8;
//	int *ptr = &a;
//	ptr = &a;
	
//	printf("%d\n", a);
//	printf("%d\n", *ptr);

//	printf("%d\n", &a);
//	printf("%d\n", ptr);
	
//	*ptr = 10;
//	printf("%d\n", a);
//	printf("%d\n", *ptr);
	
	char huruf = 'O';
	char *ptr = &huruf;
	char **ptrr;
	
	ptr = &huruf;
	ptrr = &ptr;
	
	printf("%c\n", huruf);
	printf("%c\n", *ptr);
	printf("%c\n", **ptrr);

	
	


	
	
	
	
	return 0;
}