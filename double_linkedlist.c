#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *prev;
	struct Node *next;
};
typedef struct Node node;
node *head=NULL;
node * tail=NULL;
node *newnode()
{ 
 node *p;
 p=(node *)malloc(sizeof(node));
 return p;
}

void displayaltor()
{
	 node *curr=head;
	 if(head==NULL)
		printf("List is empty\n");
	 else
	 {
	 	while(curr!=NULL)
	 	{
	 		printf("%d\t",curr->info);
	 		curr=curr->next;
	 	}
	 }
}

void displayartol()
{
	 node *curr=tail;
	 if(tail==NULL)
		printf("List is empty\n");
	 else
	 {
	 	while(curr!=NULL)
	 	{
	 		printf("%d\t",curr->info);
	 		curr=curr->prev;
	 	}
	 }
}

void insertfirst(int val)
{
	node *p=newnode();
	p->info=val;
	p->prev=NULL;
	p->next=head;
	if(head==NULL)
		head=tail=p;
	else
	{
		head->prev=p;
		head=p;
	}
}

void insertlast(int val)
{
	node *p=newnode();
	p->info=val;
	p->next=NULL;
	p->prev=tail;
	if(tail==NULL)
		head=tail=p;
	else
	{
		tail->next=p;
		tail=p;
	}
}

void insertafter(int item,int val)
{
	node *p=newnode();
	p->info=val;
	node *curr=head;
	while(curr->info!=item && curr!=NULL)
		curr=curr->next;
	if(curr==NULL)
	{
		p->next=NULL;
		p->prev=tail;
		tail->next=p;
		tail=p;
	}
	else
	{
		p->next=curr->next;
		p->prev=curr;
		curr=curr->next;
		curr->prev=p;
		curr=p->prev;
		curr->next=p;
	}
}

void insertbefore(int item,int val)
{
	node *p=newnode();
	p->info=val;
	node *curr=head;
	while(curr!=NULL && curr->info!=item)
		curr=curr->next;
	if(curr==NULL)
		printf("No such Node exists!\n");
	else
	{
		p->next=curr;
		p->prev=curr->prev;
		if(curr->prev!=NULL)
			curr->prev->next=p;
		curr->prev=p;
		if(curr==head)
			head=p;
	}
}

void deletenode(int item)
{
	node * curr=head;
	while(curr!=NULL && curr->info!=item)
		curr=curr->next;
	if(curr==NULL)
		printf("Mo such Node exists!\n");
	else
	{
		if(curr->prev==NULL)
			head=curr->next;
		else
			curr->prev->next=curr->next;
		if(curr->next==NULL)
			tail=curr->prev;
		else
			curr->next->prev=curr->prev;
		free(curr);
	}
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
		printf("\n1) Insert at First\n2) Insert at Last\n3) Insert Before\n4) Insert After\n5) Delete\n6) Display From Left to Right\n7) Display From Right to Left\n8) Exit\n");
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
				deletenode(j);
				break;
			case 6:
				displayaltor();
				break;
			case 7:
				displayartol();
				break;
			case 8:
				cl();
				break;
			default:
				printf("Wrong Input!\n");
		}
	}while(ch!=8);
}


