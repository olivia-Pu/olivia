#include <stdio.h>
#include <math.h>
int main()
{
	int s=0,a=0,i;
	for(i=1;i<=5;i++)
	{
		a=a*10+3;
		s=s+a;
	}
	printf("%d",s);
	getch();
	return 0;
 } 
