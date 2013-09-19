/* changed file */
/*#########implementation of circular linked list delete############################*/

#include<stdio.h>
#include<malloc.h>

/*########################Declearing the structure ####################*/

typedef struct ll
{
	
	int data;
	struct ll *next;
}node;

/*#########################declearing the functions###########################*/

void cret(node **header, int *c, int n);/*here header will store the address of the head*/
void del(node **header , int *c, int n);/*c store the no. of nodes*/
void disp(node **header , int c);/*display the node */
void instbefo(node **header, int t,int v,int *c);/* t store the target value*/
void instaft(node **header, int t,int v,int *c);

/*####################### MAIN FUNCTION #################################*/

int main(void)
{

	int i =10, value ,n ,a ,t ,count =0;
	node *head = NULL;
	while(i)
	{
		printf("Create :: 1\nDelete :: 2\nCount :: 3\nDisplay :: 4\nInsert a node before a node :: 5\nInsert a node after a node :: 6\nExit :: 0\n");
		scanf("%d",&i);
		
		switch(i)
		{
		/*for creation and insertion in he loop*/

			case 1: printf("please enter a value\n");
				scanf("%d",&n);
				cret(&head , &count , n);
				break;

		/*for deletion of a node*/

			case 2: printf("Enter the value to be deleted\n");
				scanf("%d",&n);
				del(&head , &count , n);
				break;

		/*for count the node */

			case 3: printf("The no. of node is %d\n", count);
				break;

		/*for displaying the node*/

			case 4: disp(&head ,count);
				break;
		/*for insert a node before a node*/
			
			case 5: printf("Enter the target value\n");
				scanf("%d",&t);
				printf("Enter the no. to be inserted\n");
				scanf("%d",&a);
				instbefo(&head , t, a, &count);
				break;
 			case 6: printf("Enter the target value\n");
				scanf("%d",&t);
				printf("Enter the no. to be inserted\n");
				scanf("%d",&a);
				instaft(&head, t, a, &count);
				break;
			
			
			
						
		}
	}
	return 0;
}


void cret(node **header, int *c, int n)
{
	int i;

	node *current;
	if(*header == NULL)
	{
		(*header)=(node *)malloc( sizeof(node));
		(*header) -> data = n;
		(*header) -> next = (*header);
		(*c)++;

		return;
	}
	i = (*c);
	current = *header;
	
	while(i>1)
	{
		current = current -> next;
		i--;
	}
	current -> next = (node *)malloc(sizeof(node));
	current -> next -> data = n;
	current -> next -> next = (*header);
	current = current -> next;
	(*c)++;
}

void del(node **header, int *c, int n)
{

	int i=*c;
	node *current , *prev;
	if(*header == NULL )
	{
		printf("The linked list is empty \n");
		return;
	}
	current = (*header);
	
	while(i>0)
	{
		if(current -> data == n)
		{
			printf("The node [%d] is deleted\n",n);
			(*c)--;
			break;
		}

		else
		{
			prev =current;
			current =current -> next;
		}	i--;

	}
	if(current -> data == n )
	{
		if(current != *header)
		{
			prev -> next =current -> next;
		}
		else
		(*header) = current -> next;
	}
	else
	printf("The no. is not found\n");
	
			
}	

			


void disp(node **header,int c)
{

	int i;
	i = c;
	printf("HEAD -->");
	
	while(i > 0)
        {
		printf("[%d] -->",(*header) -> data);
		(*header) = (*header) -> next;
		i--;
	}
	printf("HEAD\n");
}

void instbefo(node **header, int t,int v,int *c)
{
	node *current, *temp, *prev;
	if( *header == NULL)
	{
		printf("ERROR");
		return ;
	}
	current = prev = *header;
	while(current != NULL)
	{
		if(current -> data == t)
			break;
		else
		{
			prev = current ;		
			current =current -> next;
		}
	}

	if(current -> data !=  t)
	{
		printf("Data is not found\n");
		return;
	}
	
	
	
	temp =(node *)malloc(sizeof(node));
	temp -> data = v;
	temp -> next = current;
	if(current == *header)
	{
		*header = temp;		
		(*c)++;
		return ;
	}
		
		prev -> next = temp;
		(*c)++;
		
}

void instaft(node **header, int t, int v, int *c)
{
	node *current, *prev ,*temp;
	if(*header == NULL )
	{
		printf("ERROR");

	}
	current = prev = *header;
	while(*c >= 1)
	{
		if(current -> data = t)
			break;
		else
		{
			prev = current;
			current = current -> next;
		}
	}
	if(current == NULL)
	{
		printf("The target is not found");
		return;
	}
	temp = (node*)malloc(sizeof(node));		
	temp -> data = v;
	temp -> next = current -> next;
	current ->next = temp;
	(*c)++;
	
}
	


 

		



