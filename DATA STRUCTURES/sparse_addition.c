#include<stdio.h>
void readnum(int [][20],int,int);
int sparse(int [][20],int,int,int [][3],int,int);
void printmat(int [][20],int,int);
void printsparse(int [][3],int,int,int);
//void addsparse(int [][3],int,int,int [][3],int,int);

void main()
{
	int rno,cno,count1,count2;
	printf("Enter the number of rows: ");
	scanf("%d",&rno);
	printf("Enter the number of columns: ");
	scanf("%d",&cno);
	int mat1[rno][cno],S1[20][3],mat2[rno][cno],S2[20][3];
	readnum(mat1,rno,cno);
	//readnum(mat2,rno,cno);
	printmat(mat1,rno,cno);
	//printmat(mat2,rno,cno);
	count1=sparse(mat1,rno,cno,S1,20,3);
	printsparse(S1,20,3,count1);
	//count2=sparse(mat2,rno,cno,S2,20,3);
	//printsparse(S2,20,3,count2);
	//addsparse(S1,rno,cno,S2,count1+1,count2+1);
}

void readnum(int mat[][20],int rno1,int cno1)
{
	int i,j;
	printf("Enter %d numbers: ",rno1*cno1);
	for(i=0;i<rno1;i++)
		for(j=0;j<cno1;j++)
			scanf("%d",&mat[i][j]);
}

int sparse(int mat[][20],int rno1,int cno1,int S[][3],int rno2,int cno2)
{
	int i,j,k=1,count=0;
	S[0][0]=rno1;
	S[0][1]=cno1;
	for(i=0;i<rno1;i++)
		for(j=0;j<cno1;j++)
			if(mat[i][j]!=0)
			{
				S[k][0]=i;
				S[k][1]=j;
				S[k][2]=mat[i][j];
				k++; count++;
			}
	S[0][2]=count;
	return count;
}

void printmat(int mat[][20],int rno1,int cno1)
{
	int i,j;
	printf("\nThe Matrix is:\n");
	for(i=0;i<rno1;i++)
	{
		for(j=0;j<cno1;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}

void printsparse(int S[][3],int rno,int cno2,int count)
{
	int i,j;
	printf("\nThe Triplet Representation is:\n");
	for(i=0;i<count+1;i++)
	{
		for(j=0;j<cno2;j++)
			printf("%d\t",S[i][j]);
		printf("\n");
	}
}

/*void addsparse(int S1[][3],int rno,int cno,int S2[][3],int count1,int count2)
{
	int i,j,m,n,count=0;
	int S3[20][3];
	S3[0][0]=rno;
	S3[0][1]=cno;
	for(i=0;i<20;i++)
		for(j=0;j<3;j++)
			S3[i][j]=0;
	for(i=1;i<count1;i++)
		for(j=0;j<3;j++)
		{
			m=S1[i][0];
			n=S1[i][1];
			S3[m][n]=S1[i][2];
		}
	for(i=1;i<count2;i++)
		for(j=0;j<3;j++)
		{
			m=S2[i][0];
			n=S2[i][1];
			if(S3[m][n]==0)
				S3[m][n]=S2[i][2];
			else
				S3[m][n]+=S2[i][2];
		}
	for(i=1;i<rno1;i++)
		for(j=0;j<cno1;j++)
			if(S3[i][j]!=0)
				count++;
	S3[0][2]=count;
	printsparse(S3,cno1,count+1);
}*/
	
