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

void insertfirst(int val)
{
	node *p=newnode();
	p->info=val;
	p->next=head;
	head=p;
}

void insertlast(int val)
{
	if(head==NULL)
		insertfirst(val);
	else
	{
		node *curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		node *p=newnode();
		p->info=val;
		curr->next=p;
		p->next=NULL;
	}
}

void insertbefore(int item,int val)
{
	node *prev=NULL;
	node *curr=head;
	while(curr->info!=item)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==head)
		insertfirst(val);
	else
	{
		node *p=newnode();
		p->info=val;
		p->next=curr;
		prev->next=p;
	}
}

void insertafter(int item,int val)
{
	node *curr=head;
	while(curr->info!=item)
		curr=curr->next;
	if(curr->next==NULL)
		insertlast(val);
	else
	{
		node *p=newnode();
		p->info=val;
		p->next=curr->next;
		curr->next=p;
	}
}

void delete(int item)
{
	node *prev=NULL;
	node *curr=head;
	while(curr->info!=item && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==head && curr->next==NULL)
		head=NULL;
	else if(curr==head)
		head=curr->next;
	else if(curr->next==NULL)
		prev->next=NULL;
	else
		prev->next=curr->next;
	free(curr);
}

void display()
{
	node *curr=head;
	if(head==NULL)
		printf("List is empty");
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
		printf("\n1) Insert at First\n2) Insert at Last\n3) Insert Before\n4) Insert After\n5) Delete\n6) Display\n7) Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				insertfirst(j);
				break;
			case 2:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				insertlast(j);
				break;
			case 3:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				printf("Enter the element to be searched: ");
				scanf("%d",&k);
				insertbefore(k,j);
				break;
			case 4:
				printf("Enter the element to be inserted: ");
				scanf("%d",&j);
				printf("Enter the element to be searched: ");
				scanf("%d",&k);
				insertafter(k,j);
				break;
			case 5:
				printf("Enter the element to be deleted: ");
				scanf("%d",&j);
				delete(j);
				break;
			case 6:
				display();
				break;
			case 7:
				cl();
				break;
			default:
				printf("Wrong Input!");
		}
	}while(ch!=7);
}
