#include<stdio.h>
int top=0,size=10;
char a[10];

int isfull()
{
	if(top==size)
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

void push(char value)
{
	//if(isfull()==1)
	//	printf("The Stack is full!\n");
	//else
		a[top++]=value;
}

char pop()
{
	//if(isempty()==1)
	//	printf("The Stack is Empty!\n");
	//else
		return a[--top];
}

char peek()
{
	//if(isempty()==1)
	//	printf("The Stack is Empty!\n");
	//else
		return a[top-1];
}

int instackprio(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return (2);
			break;
		case '*':
		case '/':
			return (4);
			break;
		case '^':
			return (5);
			break;
		case '(':
			return (0);
			break;
	}
}

int inputprio(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return (1);
			break;
		case '*':
		case '/':
			return (3);
			break;
		case '^':
			return (6);
			break;
	}
}

void main()
{
	char inf[100],post[100];
	int i=0,j=0;
	printf("Enter the Infix expression:\n");
	scanf("%s",inf);
	for(i=0;inf[i]!='\0';i++)
	{
		switch(inf[i])
		{
			case '(':
				push(inf[i]);
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while(!isempty() && inputprio(inf[i])<instackprio(peek()))
					post[j++]=pop();
				push(inf[i]);
				break;
			case ')':
				while(peek()!='(')
				post[j++]=pop();
				pop();
				break;
			default:
				post[j++]=inf[i];
		}
	}
	while(!isempty())
		post[j++]=pop();
	post[j]='\0';
	puts(post);	
}
