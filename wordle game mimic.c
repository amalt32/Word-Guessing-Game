#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag=0;
int count;
int i,j;
char a[5], a1[5], c[5],str[20];
struct node
{
	char data;
 	struct node *next;
};
struct node *list1 = NULL;
struct node *list2 = NULL;
void insert(struct node **list, char e)//LinkedList Insertion
{
	struct node *t;
 	if (*list == NULL)
 	{
 		*list = (struct node *)malloc(sizeof(struct node));
 		(*list)->data = e;
 		(*list)->next = NULL;
 	}
 	else
 	{
 		t = *list;
 		while (t->next != NULL)
 		{
 			t = t->next;
 		}
 		t->next = (struct node *)malloc(sizeof(struct node));
 		t->next->data = e;
 		t->next->next = NULL;
 	}
}
int compare()// Comparing user input with secret word
{
	struct node *t1 = list1;
 	struct node *t2 = list2;
 	int count=0;
 	while (t1 != NULL && t2 != NULL)
 	{
 		if (t1->data == t2->data)
 		{
 			printf("%c", t2->data);
 			t1 = t1->next;
 			t2 = t2->next;
 			count=count+1;
 		}		
 		else
 		{
 			t2->data = 'x';
 			printf("%c", t2->data);
 			t2 = t2->next;
		}
	}
 	return(count);
}	
void guess()
{
	int i,j;
	printf("\nGuess the word:");
 	scanf("%s", a1);
 	printf("Guessed word is: ");
 	for (j = 0; j < 5; j++)
 	{
 		insert(&list2, a1[j]);
 	}
 	
 	
}
void deleteLinkedList(struct node **list) //deleting the user string if it's wrong
{
	struct node *current = *list;
 	struct node *next;
 	while (current != NULL) 
	{
		next = current->next;
 		free(current);
 		current = next;
 	}
 	*list = NULL;
}
int main()
{
 	struct node *t2;
 	printf("Enter a 5-letter secret word: _ _ _ _ _\n");
 	scanf("%s", a);
 	
 	//printf("\nData in linked list:");
 	for (i = 0; i < 5; i++)
 	{
 		insert(&list1, a[i]);
 	}
 	printf("\nEnter a hint:");
 	scanf(" %[^\n]s", str);
 	
 	printf("\n\n***************Game Rules**************\nGuess the secret word within 5 successful attempts!.");
 	printf("\n\n************* Game Starts ********************\n");
 	printf("Hint: %s\n", str);
 	for(i=0;i<5;i++)
 	{
 		guess();
 		count=compare();
		 if(count==5)
 		{
			printf("\n\nCongratulation, correct guess");
 			break;
 		}
 		else
 		{
 			printf("\n\nWrong guess");
 			deleteLinkedList(&list2);
 		}
	}
	return 0;
}