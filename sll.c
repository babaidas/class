/*implementation of single linked list*/

#include<stdio.h>
#include<malloc.h>

/*decearing structure for linked list*/

typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;

/*declearing the functions*/

void cret(node **head, int value,int *c);
void trev(node **head,int c);
//void instaft(node **head,int value,int target);
//void inatbfo(node **head.int value,int target);

/*############################  MAIN  #################################*/

int main(void)

{

	int n = 10,a=0,value;
	node *head = NULL;

	while(n)
	{
		printf("1 : Creat\n2 : Treversal\n3 : Insert after \n4:Insert before\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("Please enter a value\n");
				scanf("%d",&value);
				cret(&head,value,&a);
				break;
			case 2: trev(&head,a);
				break;
		}
	}
	return 0;
}

/*#######################  INSERT FUNCTION  #########################*/

void cret(node **head ,int value,int *c)
{
 
	node *current;
 
/*#####################creation of first node ######################*/
	if(*head == NULL )
	{
		
		*head = (node *)malloc( sizeof(node));
		(*head)->data = value;
		(*head)->next = NULL;
		(*c)++;
		
	}
	
/*##################creation of nodes after first node#############*/

	else
	{
		
		current = (*head) -> next;
		while(current != NULL)
		{

			if(current == NULL)
			{
				current->next =(node *)malloc(sizeof(node));
				current->next->data = value;
				current->next->next = NULL ;
				current=current->next;
				(*c)++;
				printf("%d",*c);
			}
			else

			{
				current = current->next;
			}
		}
	}
}

/*###############Treversal of nodes###########################*/

void trev(node **head,int c)
{
	printf("HEAD--->");
	while(c > 0 )
	{
		printf(" [ %d ]--->",(*head) -> data);
		(*head) = (*head) -> next;
		c--;
	}
	printf("NULL\n");
}




	

