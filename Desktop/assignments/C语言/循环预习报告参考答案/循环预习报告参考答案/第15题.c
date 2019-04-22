#include <stdio.h> 
#include <math.h>
int main()
{   
    int i,n,s;
    for(n=1;n<=1000;n++)
    {
    	s=0;
        for(i=1;i<n;i++)
        {
    	   if(n%i==0)
    	   s=s+i;
	    }
	    if(i==s)
	       printf("%6d",n);
	}
	getch();
	return 0;
}
