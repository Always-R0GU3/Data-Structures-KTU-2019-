#include<stdio.h>
void readnum(int [],int);
void simplemerge(int [],int,int,int);
void merge(int [],int,int);
void printnum(int [],int);

void main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	readnum(arr,n);
	merge(arr,0,n-1);
	printnum(arr,n);
}

void readnum(int a[],int n)
{
	printf("Enter %d numbers",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void simplemerge(int a[],int f,int s,int t)
{
	int i=f,j=s,k=0;
	int temp[50];
	while(i<s && j<=t)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else if(a[i]>a[j])
			temp[k++]=a[j++];
	}
	while(i<s)
		temp[k++]=a[i++];
	while(j<=t)
		temp[k++]=a[j++];
	for(k=0,i=f;i<=t;)
		a[i++]=temp[k++];
}

void merge(int a[],int beg,int end)
{
	if(beg<end)
	{
		int mid;
		mid=(beg+end)/2;
		merge(a,beg,mid);
		merge(a,mid+1,end);
		simplemerge(a,beg,mid+1,end);
	}
}

void printnum(int a[],int n)
{
	printf("\nSorted Array is:\n");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
