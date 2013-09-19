
/*implementetion of the doubly linked list */

#include<stdio.h>
#include<malloc.h>

/*declearing the structure */

typedef struct ll
{
	struct ll *pred;
	int data;
	struct  ll *succ;
}node;

/*#########################declearing the functions###########################*/

void cret(node **header, int *c, int n);/*here header will store the address of the head*/
void del(node **header , int *c, int n);/*c store the no. of nodes*/
/*void disp(node **header , int c);/*display the node */
/*void instbefo(node **header, int t,int v,int *c);/* t store the target value*/


/*####################### MAIN FUNCTION #################################*/

int main(void)
{

	int i =10, value ,n ,a ,t ,count =0;
	node *head = NULL;
	while(i)
	{
		printf("Create :: 1\nDelete :: 2\nCount :: 3\nDisplay :: 4\nInsert a node before a node :: 5\nExit :: 0\n");
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

		/*	case 4: disp(&head ,count);
				break;
		/*for insert a node before a node*/
			
		/*	case 5: printf("Enter the target value");
				scanf("%d",&t);
				printf("Enter the no. to be inserted");
				scanf("%d",&a);
				instbefo(&head , t, a, &count);
				break;*/
 
			
			
			
						
		}
	}
	return 0;
}

void cret(node **header, int *c, int n)
{
	int i;

	node *current, *temp, *prev;
	if(*header == NULL)
	{
		(*header)=(node *)malloc( sizeof(node));
		(*header) -> data = n;
		(*header) -> pred = NULL;
		(*header) -> succ = NULL;
		(*c)++;
		return;
	}
	i = (*c);
	current = *header;
	
	while(i>1)
	{
		prev =current;
		current = current -> succ;
		i--;
	}
	temp = (node *)malloc(sizeof(node));
	temp -> data = n;
	temp -> pred = prev;
	temp -> succ = NULL;
	current -> succ = temp;
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
	prev = current = (*header);
	
	while(i>0)
	{
		if(current -> data == n)
		{
			free(current);
			printf("The node [%d] is deleted\n",n);
			(*c)--;
			break;
		}

		else
		{
			prev =current;
			current =current -> succ;
		}	i--;

	}
	if(current -> data == n )
	{
		if(current != *header)
		{
			prev -> succ =current -> succ;
		}
		else
		(*header) = current -> succ;
	}
	else
	printf("The no. is not found\n");
	
			
}	

void disp(node **header,int c)
{

	int i;
	i = c;
	printf("NULL -->");
	
	while(i > 0)
        {
		printf("[%d] -->",(*header) -> data);
		(*header) = (*header) -> succ;
		i--;
	}
	printf("NULL\n");
}


