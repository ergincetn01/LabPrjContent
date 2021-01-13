#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#define PSW_SIZE 50

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

int main()
{
    int opt;
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
    return 0;
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
