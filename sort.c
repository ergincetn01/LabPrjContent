#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define FILE_SIZE 10000
#define COL 35
 
 
void printArray(char array[FILE_SIZE][COL], int size)
{
    int i;
    for (i = 0; i < size ; i++) {
        printf("%s\n", array[i]);
    }
}
void bubblesortchar(char array[FILE_SIZE][COL], int size) {
	int i, j;
	char temp[1][30];

	for (i = 0; i < size; i++) {
		for (j = 1; j < size - i; j++) {
			if (strcmp(array[j - 1] , array[j])>0) {
				strcpy(temp[0] , array[j]);
				strcpy(array[j] , array[j - 1]);
				strcpy(array[j - 1] , temp[0]);

			}

		}
	}
}
int main() {
 
	char storeArray[FILE_SIZE][COL] ;
	
	FILE *filePtr_10K;
	
	int i,j,k,count=0;

	printf("---SORTING---\n\n");

	filePtr_10K = fopen("10-million-password-list-top/10000.txt", "r");
	
	if(filePtr_10K==NULL) {
		printf("Error when accessing the file!");
		exit(EXIT_FAILURE);
	}
	else{
		while (!feof(filePtr_10K)) {
	 
			fscanf(filePtr_10K, "%s\n", storeArray[count]);
			count++;
		}
	fclose(filePtr_10K);
	
	}

	bubblesortchar(storeArray, FILE_SIZE);
	printf("--First 100 elements in ascending order--\n");
	for(j=0; j<100; j++){
		printf("%s -  ", storeArray[j]);
	}
	

	return 0;
}
