#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	printf("%d",F(n));
	return 0;
}
int F(int n)
{int x;
 if(n==0||n==1)
	   return 1;
	   	else x=F(n-1)+F(n-2);
	   return x;
	 	
}
