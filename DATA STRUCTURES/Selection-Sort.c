#include<stdio.h>
void readnum(int [],int);
void printnum(int [],int);
void sel_sort(int [],int);
void swap(int *,int*);

void main()
{
    int n;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    sel_sort(a,n);
    printnum(a,n);
}

void readnum(int x[],int n)
{
    int i;
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
}

void printnum(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",x[i]);
}

void sel_sort(int x[],int n)
{
    int p,lar,ind,c;
    for(p=0;p<n-1;p++)
    {
        lar=x[0];
        ind=0;
        for(c=1;c<n-p;c++)
        {
            if(x[c]>lar)
            {
                lar=x[c];
                ind=c;
            }
        }
        swap(&x[ind],&x[n-p-1]);
    }
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
