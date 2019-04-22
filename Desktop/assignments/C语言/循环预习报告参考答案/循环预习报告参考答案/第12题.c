#include <stdio.h>
#include <math.h>
int main()
{
	int s=0,a=1,i;
	for(i=1;i<=5;i++)
	{
		a=a*i;
		s=s+a;
	}
	printf("%d",s);
	getch();
	return 0;
 } 
