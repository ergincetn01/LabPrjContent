#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define LL_FI_SIZE 1000
#define COL 35

char *storeForLinked[LL_FI_SIZE][COL];

void printArray(char array[LL_FI_SIZE][COL], int size)
{
    int i;
    for (i = 0; i < size ; i++) {
        printf("%s\n", array[i]);
    }
}

//node implementation with struct
struct node{
	char *password[LL_FI_SIZE][COL];
	struct node *next;
};


typedef struct linkedlist{
	char password[LL_FI_SIZE][COL];
	struct linkedlist *next;
	
}LINKEDLIST;


void readForLinkedList() {
	FILE *LL_filePtr_1K;
	
	int i,j,k,count=0;
	LL_filePtr_1K = fopen("10-million-password-list-top/1000.txt", "r");
	
	if(LL_filePtr_1K==NULL) {
		printf("Error when accessing the file!");
		exit(EXIT_FAILURE);
	}
	else{
		while (!feof(LL_filePtr_1K)) {
	 
			fscanf(LL_filePtr_1K, "%s\n", storeForLinked[count]);
			count++;
		}
	fclose(LL_filePtr_1K);
	
	}	
}

struct node *arrayToList(char array[LL_FI_SIZE], int size){
	int i;
	struct node *head=NULL, *temp=NULL, *current=NULL;
	for(i=0; i<LL_FI_SIZE; i++){
		temp=(struct node *)malloc(sizeof(struct node));
		temp->password=storeForLinked[i];
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			current=temp;
		}
		else{
			current->next=temp;
			current =current->next;
		}
	}
}


int main() {
	readForLinkedList();
	printf("original array::::::");
	printArray(storeForLinked, LL_FI_SIZE);
	struct node *head;
	head=arrayToList(storeForLinked, LL_FI_SIZE);
	while(head!=NULL){
		printf("%s\n", head->password);
		head=head->next;
	}

	return 0;
}
