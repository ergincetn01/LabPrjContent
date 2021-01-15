#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#define PSW_SIZE 50
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

int indexOf(FILE *filePtr, const char *strToSearch, int *line, int *col);

void search_in_file() {
	clock_t start1, end1;
	double totaltime;
	FILE *filePtr_100K;
    char searchKey[50];
    int line, col;
    
    printf("Type a data to search in the '100.000.txt' file : ");
    scanf("%s", searchKey);
    start1 = clock(); //time counter started

    filePtr_100K = fopen("10-million-password-list-top/100000.txt", "r");

    if (filePtr_100K == NULL)
    {
        printf("Cannot access/open this file!\n");
        exit(EXIT_FAILURE);
    }

    indexOf(filePtr_100K, searchKey, &line, &col);

    if (line != -1)
        printf("'%s' found at line: %d \n", searchKey, line + 1, col + 1);
    else
        printf("'%s' could not be found in file!\n", searchKey);
	end1 = clock(); //time counter ended
    fclose(filePtr_100K);
    totaltime = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Time for this searching is:\t%f", totaltime);
		
}

int indexOf(FILE *filePtr, const char *strToSearch, int *line, int *col)
{
    char tempString[PSW_SIZE];
    char *posPtr;

    *line = -1;
    *col  = -1;

    while ((fgets(tempString, PSW_SIZE, filePtr)) != NULL)
    {
        *line += 1;
        posPtr = strstr(tempString, strToSearch);
        if (posPtr != NULL)
        {
            *col = (posPtr - tempString);
            break;
        }
    }

    if (*col == -1)
        *line = -1;

    return *col;
}
int main()
{
    int opt;
    clock_t start2, end2;
 	double totaltime;
	char storeArray[FILE_SIZE][COL] ;
	FILE *filePtr_10K;
	int i,j,k,count=0;
	setlocale(LC_ALL,"Turkish");
	printf("---SEARCHING---");
	do
	{
		printf("\n 1: Make a search - 0: EXIT. Enter your choose: ");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1: 
				search_in_file();
				break;
			
		}
	} while (opt != 0);
	
	printf("\n\n");
	
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
	
	start2=clock(); 
	bubblesortchar(storeArray, FILE_SIZE);
	end2=clock();
	
	totaltime = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("Time for sorting with bubble sort is: %f\n", totaltime);
	
	printf("--First 100 elements in ascending order--\n");
	for(j=0; j<100; j++){
		printf("%s -  ", storeArray[j]);
	}
	printf("\n\n");
	
	printf("--last 100 elements in descending order--\n");
		for(j=FILE_SIZE-1; j>FILE_SIZE-101; j--)
			printf("%s - ", storeArray[j]);
    return 0;
}


