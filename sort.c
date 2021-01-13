#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define FILE_SIZE 10000
#define COL 35

int main() {
	clock_t start2, end2;
	char storeArray[FILE_SIZE][COL];
	FILE *filePtr_10K;
	int i;
	int k;
	
	printf("---SORTING--- \n");
	filePtr_10K=fopen("10-million-password-list-top/10000.txt", "r");
	
	if(filePtr_10K==NULL) {
		printf("Error when accessing the file!");
		exit(EXIT_FAILURE);
	}
	else{
		for(i=0;i<FILE_SIZE;i++){
			fgets(storeArray[i], FILE_SIZE, filePtr_10K);
		}
	
	}

	fclose(filePtr_10K);
	
	for(k=0;k<FILE_SIZE;k++){
		printf("%s", storeArray[k]);
	}
	
	return 0;
}
