#include <stdio.h>
int main ()
{
	int i,j,x,s=0,a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	for (i=0;i<=2;i++)
	{
		for (j=0;j<=2;j++)
		{  
			printf ("%3d",a[i][j]);
		}
		printf ("\n");
	}
	for (i=0;i<=2;i++)
	{
		for (j=0;j<=2;j++)
	        if(i==j)
	        s=s+a[i][j];
	}
	printf("对角线元素之和为%5d",s);
	return 0;
 } 
