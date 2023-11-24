#include<stdio.h>
void readnum(int [],int);
void in_sort(int [],int);
void printnum(int [],int);

void main()
{
    int n;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    in_sort(a,n);
    printnum(a,n);
}

void readnum(int x[],int n)
{
    int i;
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
}

void in_sort(int x[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=x[i];
        j=i-1;
        while(j>=0 && x[j]>key)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=key;
    }
}

void printnum(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",x[i]);
}
