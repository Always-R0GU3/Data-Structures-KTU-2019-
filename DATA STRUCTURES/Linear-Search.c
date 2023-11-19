#include<stdio.h>
void readnum(int [],int);
int linear_search(int [],int);

void main()
{
    int n,ans;
    printf("Enter how many numbers:\n");
    scanf("%d",&n);
    int a[n];
    readnum(a,n);
    ans=linear_search(a,n);
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

int linear_search(int a[],int n)
{
    int i,num,index;
    printf("Enter the number to be searched");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(num==a[i])
        {
            index=i;
            return index;
        }
    }
    return -1;
}
