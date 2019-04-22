#include <stdio.h> 
#include <math.h>
int main()
{   
    int i,n,s=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
    	if(n%i==0)
    	   s=s+i;
	}
	if(i==s)
	  printf("%d是完数",n);
	else
	  printf("%d不是完数",n);
	getch();
	return 0;
}
