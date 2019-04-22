#include <stdio.h>
int main ()
{
	int c[11],i,n=10;
    for (i=1;i<=n;i++)
	scanf("%d",&c[i]);
	selection_sort (c);
	for (i=1;i<=n;i++)
	printf ("%5d",c[i]);
	return 0;	
}
int selection_sort (int c[])
{int i,j,n=10,temp;
for(i=1;i<=n-1;i++)
{for(j=1;j<=n-i;j++)
 if(c[j]>c[j+1])
      {temp=c[j];
      c[j]=c[j+1];
      c[j+1]=temp;
	  }
}
}
