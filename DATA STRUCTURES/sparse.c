#include<stdio.h>
void main()
{
	int rno,cno,i,j,k=1;
	printf("Enter the number of rows:\n");
	scanf("%d",&rno);
	printf("Enter the number of columns:\n");
	scanf("%d",&cno);
	int mat[rno][cno],sp[rno+1][3];
	printf("Enter the elements of the Matrix:\n");
	for(i=0;i<rno;i++)
		for(j=0;j<cno;j++)
			scanf("%d",&mat[i][j]);
	for(i=0;i<rno;i++)
		for(j=0;j<cno;j++)
			if(mat[i][j]!=0)
			{
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=mat[i][j];
				k++;
			}
	sp[0][0]=rno;
	sp[0][1]=cno;
	sp[0][2]=k;
	printf("\nThe Sparse Matrix Representation is:\n");
	for(i=0;i<k;i++)
		{
			for(j=0;j<3;j++)
				printf("%d\t",sp[i][j]);
			printf("\n");
		}
}
