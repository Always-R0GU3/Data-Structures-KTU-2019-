#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *next;
};
typedef struct{
	int cons;
	int expo;
	struct node *next;
}term;

term poly[10];
term *poly=new term();

node *readpoly()
{
	node *head,*curr;
	int ch;
	head=newnode();
	curr=head;
	do{
		printf("Enter constant and power: ");
		scanf("%d %d",&curr->cons,&curr->expo);
		printf("\nDo you have more terms?\n1) Yes\n2) No");
		scanf("%d",&ch);
		if(ch==1)
		{
			curr->next=newnode();
			curr=curr->next;
		}
	}while(ch==1);
	curr->next=NULL;
	return head;
}

node *addpoly(node *A,node *B)
{
	node *c,*curr;
	c=newnode();
	curr=c;
	while(A!=NULL && B!=NULL)
	{
		if(A->expo==B->expo)
		{
			curr->cons=A->cons+B->cons;
			curr->expo=A->expo;
			A=A->next;
			B=B->next;
		}
		else if()
	}
}
