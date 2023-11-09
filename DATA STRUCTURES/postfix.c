#include<stdio.h>
int top=0,size=100;
char post[100];

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

void push(char value)
{
	if(isfull()==1)
		printf("The Stack is full!\n");
	else
		post[top++]=value;
}

char pop()
{
	if(isempty()==1)
		printf("The Stack is Empty!\n");
	else
		return post[--top];
}

char peek()
{
	if(isempty()==1)
		printf("The Stack is Empty!\n");
	else
		return post[top-1];
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
			printf("%c\n",post[i]);
		printf("\n");
	}
}

void displaypost()
{
	for(int i=0;post[i]!='\0';i++)
		printf("%c",post[i]);
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
			return (5);
			break;
	}
}




void main()
{
	char inf[100],token,c;
	int i=0,j=0;
	printf("Enter the Infix expression:\n");
	scanf("%s",inf);
	while (inf[i]!='\0')
	{
		token=inf[i];
		switch(inf[i])
		{
			case '(':
				push(token);
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while((!isempty() && instackprio(peek()))>inputprio(token))
				post[j++]=pop();
				push(token);
				break;
			case ')':
				while((c=pop())!='(')
				post[j++]=c;
				break;
			default:
				post[j++]=token;
		}
		//printf("\nToken=%c",token);
		//display();
		//displaypost(post,i);
		i++;
	}
	displaypost();
}
