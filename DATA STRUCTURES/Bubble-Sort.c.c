#include<stdio.h>
void readnum(int [],int);
void sortnum(int [],int);
void printnum(int [],int);
void swap(int *,int*);

void main()
{
    int n;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    sortnum(a,n);
    printnum(a,n);
}

void readnum(int x[],int n)
{
    int i;
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
}

void sortnum(int x[],int n)
{
    int p,c,noexchange;
    for(p=1;p<n;p++)
    {
        noexchange=1;
        for(c=0;c<n-p;c++)
        {
            if(x[c]>x[c+1])
            {
                swap(&x[c],&x[c+1]);
                noexchange=0;
            }
        }
        if(noexchange==1)
                return;
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
    for(i=0;i<n;i++)
        printf("%d\t",x[i]);
}
