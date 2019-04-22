#include <stdio.h>
int main ()
{
	int i,j,a[10][10];
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j==1||j==i)
		   { 
		        a[i][j]=1;
	 	   }
			else a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
