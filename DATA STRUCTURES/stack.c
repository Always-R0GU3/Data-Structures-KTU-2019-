#include<stdio.h>
#define size 10
int s[size];
int top=0;

int isfull();
int isempty();
void push(int);
int pop();
void peek();
void display();

void main()
{
	int ch,val;
	do{
		printf("1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit\n");
		printf("Enter your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be added: ");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				printf("The Deleted element is: %d\n",pop());
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				break;
			default:
				printf("Wrong Input!\n");
				break;
		}	
	} while(ch!=5);
}

int isfull()
{
	if(top>=size)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(top==0)
		return 1;
	else
		return 0;
} 

void push(int value)
{
	if(isfull()==1)
		printf("The Stack is full!\n");
	else
		s[top++]=value;
}

int pop()
{
	if(isempty()==1)
		printf("The Stack is Empty!\n");
	else
		return s[--top];
}

void peek()
{
	if(isempty()==1)
		printf("The Stack is Empty!\n");
	else
		printf("%d\n",s[top-1]);
}

void display()
{
	if(isempty()==1)
		printf("The Stack is Empty!\n");
	else
	{
		printf("\nStack is:\n");
		int i=top-1;
		for(;i>=0;i--)
			printf("%d\n",s[i]);
		printf("\n");
	}
}

