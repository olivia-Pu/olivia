#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}
int f(int n)
{int z;
if (n<=1) 
{
	return 1;
	}
else z=f(n-1)*n;
return z;	
}

