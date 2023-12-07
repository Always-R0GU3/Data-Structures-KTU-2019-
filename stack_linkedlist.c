#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *next;
};
typedef struct Node node;
node *top=NULL;
node *newnode()
{ 
 node *p;
 p=malloc(sizeof(node));
 return p;
}

void push(int val)
{
	node *p=newnode();
	if(p==NULL)
		printf("Memory not available");
	else
	{
		p->info=val;
		p->next=top;
		top=p;
	}
}

int pop()
{
	int item;
	if(top==NULL)
		printf("Stack is Empty!");
	else
	{
		node *p=top;
		top=top->next;
		item=p->info;
		free(p);
		return item;
	}
}

int peek()
{
	if(top==NULL)
		printf("Stack is Empty!");
	else
		return(top->info);
}

void display()
{
	node *curr=top;
	if(top==NULL)
		printf("List is empty");
	else
	{
		while(curr!=NULL)
		{
			printf("%d\n",curr->info);
			curr=curr->next;
		}
	}
	printf("\n");
}

void cl()
{
	node *curr=top;
	node *prev=NULL;
	while(curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
		free(prev);
	}
}

void main()
{
	int ch,j,k;
	do{
		printf("\n1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				push(j);
				break;
			case 2:
				printf("Deleted Element is %d",pop());
				break;
			case 3:
				printf("Top Element is %d",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				cl();
				break;
			default:
				printf("Wrong Input!");
		}
	}while(ch!=5);
}
