#include <stdio.h> 
#include <math.h>
int main()
{   
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++)
    {
    	if(n%i==0)
    	   break;
	}
	if(i>sqrt(n))
	  printf("%d是素数",n);
	else
	  printf("%d不是素数",n);
	getch();
	return 0;
}
