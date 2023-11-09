#include<stdio.h>
char ch[50];
int top=0;

int isfull();
int isempty();
void push(char);
char pop();

void main()
{
	printf("Enter the String:");
	scanf("%s",ch);
	for(int i=0;ch[i]!='\0';i++)
		push(ch[i]);
	while(!isempty())
		printf("%c",pop());
	printf("\n");
}

int isfull()
{
	if(top>=50)
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
		ch[top++]=value;
}

char pop()
{
	if(isempty()==1)
		printf("Stack is Empty!\n");
	else
		return ch[--top];
}



