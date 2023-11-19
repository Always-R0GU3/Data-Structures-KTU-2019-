#include<stdio.h>
void readnum(int [],int);
void printnum(int [],int);
void quick_sort(int [],int,int);
int part(int [],int,int);
void swap(int *,int*);

void main()
{
    int n,start,end;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    start=0;
    end=n-1;
    quick_sort(a,start,end);
    printnum(a,n);
}

void readnum(int a[],int n)
{
    int i;
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}

int part(int a[],int start,int end)
{
    int key,i,j;
    i=start+1;
    j=end;
    key=a[start];
    do{
        while(i<j && a[i]<key)
            i++;
        while(j>start && a[j]>key)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    while(i<j);
    swap(&a[start],&a[j]);
    return j;
}

void quick_sort(int a[],int start,int end)
{
    int pos;
    if(start<end)
    {
        pos=part(a,start,end);
        quick_sort(a,start,pos-1);
        quick_sort(a,pos+1,end);
    }
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void printnum(int x[],int n)
{
    int i;
    printf("Sorted array:\t");
    for(i=0;i<n;i++)
        printf("%d\t",x[i]);
}