#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *next;
};
typedef struct Node node;
node *head=NULL;
node *newnode()
{ 
 node *p;
 p=malloc(sizeof(node));
 return p;
}
node *f=NULL;
node *r=NULL;

void insertq(int val)
{
	node *p=newnode();
	if(p==NULL)
		printf("Insufficient Memory!");
	else
	{
		p->info=val;
		p->next=NULL;
		if(r==NULL)
			f=r=p;
		else
		{
			r->next=p;
			r=p;
		}
	}
}

void deleteq()
{
	int item;
	if(f==NULL)
		printf("Queue is Empty!");
	else
	{
		item=f->info;
		node *p=f;
		if(f==r)
			f=r=NULL;
		else
			f=f->next;
		free(p);
		printf("\nDeleted item is %d\n",item);
	}
}

void display()
{
	node *curr=f;
	if(f==NULL && r==NULL)
		printf("Queue is empty");
	else
	{
		while(curr!=NULL)
		{
			printf("%d\t",curr->info);
			curr=curr->next;
		}
	}
	printf("\n");
}

void cl()
{
	node *curr=head;
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
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				insertq(j);
				break;
			case 2:
				deleteq();
				break;
			case 3:
				display();
				break;
			case 4:
				cl();
				break;
			default:
				printf("Wrong Input!");
		}
	}while(ch!=4);
}
