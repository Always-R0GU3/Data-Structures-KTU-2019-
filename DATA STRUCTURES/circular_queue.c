#include<stdio.h>
int n=5;
int q[5];
int f=-1,r=-1;

int isempty()
{
	if(f==-1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(f==(r+1)%n)
		return 1;
	else
		return 0;
}

void insert()
{
	int value;
	if(isfull()==1)
		printf("The Queue is Full!\n");
	else
	{
		printf("Enter the value to be inserted:\n");
		scanf("%d",&value);
		if(isempty()==1)
			f=r=0;
		else
			r=(r+1)%n;
		q[r]=value;
	}
}

int delete()
{
	if(isempty()==1)
		printf("The Queue is Empty!\n");
	else
	{
		int val=q[f];
		if(f==r)
			f=r=-1;
		else
			f=(f+1)%n;
		return val;
	}
}

void display()
{
	if(isempty()==1)
		printf("The Queue is Empty!\n");
	else
		printf("\nThe Queue is:\n");
		if(f<=r)
		{
			for(int i=f;i<=r;i++)
				printf("%d\n",q[i]);
		}
		else
		{
			for(int i=f;i<n;i++)
				printf("%d\n",q[i]);
			for(int j=0;j<=r;j++)
				printf("%d\n",q[j]);
		}
}

void main()
{
	int ch;
	do{
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				printf("\nThe Deleted element is: %d",delete());
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Wrong Input!\n");
				break;
		}
	} while(ch!=4);
}
