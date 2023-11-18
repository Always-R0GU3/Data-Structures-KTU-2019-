#include<stdio.h>
int size=10;
int q[10];
int f=-1,r=0;

int isfull()
{
	if(((f==0)&&(r=size-1)) || (f==r+1))
		return 1;
	else
		return 0;
}

int isempty()
{
	if(f==-1)
		return 1;
	else
		return 0;
}

void insert_front()
{
	int val;
	printf("Enter the element to be inserted:\n");
	scanf("%d",&val);
	if(f<1)
		f=size-1;
	else
		f--;
	q[f]=val;
}

void insert_rear()
{
	int val;
	printf("Enter the element to be inserted:\n");
	scanf("%d",&val);
	if(isfull()==1)
		r=0;
	else
		r++;
	q[r]=val;
}

void delete_front()
{
	if(isempty()==1)
		printf("The Queue is Empty!(Underflow)\n");
	else if(f==r)
		f=r=-1;
	else if(f=size-1)
		f=0;
	else
		f=f+1;
}

void delete_rear()
{
	if(isempty()==1)
		printf("The Queue is Empty!(Underflow)\n");
	else if(f==r)
		f=r=-1;
	else
	{
		if(r=0)
			r=size-1;
		else
			r=r-1;
	}
}

void display()
{
	if(isempty()==1)
		printf("The Queue is Empty!\n");
	else
	{
		printf("The Queue is:\n");
		//int i=f;
		//while(i!=r)    
    		//{    
        	//	printf("%d ",q[i]);    
       	// 	i=(i+1)%size;    
   		//}    
    		//printf("%d",q[r]);    
    		for (int i = f; i != r; i = (i + 1) % size) 
   			 printf("%d ", q[i]);
		printf("\n");
	}    
}



void main()
{
	int ch;
	do{
		printf("\n1) Insert at Front\n2) Insert at Rear\n3) Delete at Front\n4) Delete at Rear\n5) Display\n6) Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_rear();
				break;
			case 3:
				delete_front();
				break;
			case 4:
				delete_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				break;
			default:
				printf("Wrong Input!\n");
				break;
		}
	}while(ch!=6);
}
