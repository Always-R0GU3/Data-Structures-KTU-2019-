#include<stdio.h>
void readnum(int [],int);
int binary_search(int [],int,int);

void main()
{
    int n,ans,num;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    printf("Enter the number to be searched\n");
    scanf("%d",&num);
    ans=binary_search(a,num,n);
    if(ans==-1)
        printf("Entered number is not present");
    else 
        printf("Entered number found at index %d",ans);
}

void readnum(int x[],int n)
{
    int i;
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
}

int binary_search(int a[],int num,int n)
{
    int top,bot,mid,i;
    top=0;
    bot=n-1;
    for(i=0;top<=bot;i++)
    {
        mid=(top+bot)/2;
        if(num==a[mid])
            return mid;
        else if(num>a[mid])
            top=mid+1;
        else
            bot=mid-1;
    }
    return -1;
}
