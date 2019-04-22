#include <stdio.h>
int main ()
{
	int a[11],i,n=10;
    for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	selection_sort (a);
	for (i=1;i<=n;i++)
	printf ("%5d",a[i]);
	return 0;	
}
int selection_sort (int a[])
{int i,j,n=10,k,temp;
for (i=1;i<=n-1;i++)
{k=i;
for(j=i+1;j<=n;j++)
{if(a[k]>a[j])
     k=j;
}
if(k!=i)
{temp=a[i];
a[i]=a[k];
a[k]=temp;
}
}
}
