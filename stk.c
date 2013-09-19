#include<stdio.h>
#include<malloc.h>

typedef struct

{
	int data;
	struct ll *next;
}node;

void cret(node **head,int value);
void dis(node **head);

int main()
{	
	int n,value;
	node *head;
	printf("Push :: 1\nPop :: 2\nDisplay :: 3\nExit :: 0");
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{

			case 1:scanf("%d",&value);
				cret(&head,value);
				break;
			case 2:
				break;
			case 3:dis(&head);
				break;
		}
	}
	return 0;
}

void cret(node **head,int value){
	node *current;
	if(*head == NULL)
	{
		*head = (node *)malloc(sizeof(node));
		(*head) ->data = value;
		(*head) ->next = NULL;
	}
	else
	{
		current = *head;
		while(current != NULL)
		{
			if(current -> next == NULL)
			{
				current -> next = (node*)malloc(sizeof(node));
				current -> next -> data = value;
				current -> next -> next = NULL;
			}
			else
				current = current ->next;
		}
	}
}
				
 
void dis(node **head)
{
	if(*head == NULL)
		printf("The stack is empty\n");
	else
	{
		while(head != NULL)
		printf("%d",head -> data);
	}
}g
		



