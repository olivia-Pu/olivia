#include <stdio.h> 
#include <math.h>
int main()
{   
    int i,n,k=0;
    for(n=3;n<=100;n++)
	{
        for(i=2;i<=sqrt(n);i++)
        {
    	   if(n%i==0)
    	      break;
	    }
	    if(i>sqrt(n))
	    {
	       printf("%4d",n);
	       k=k+1;
	       if(k%5==0)
	          printf("\n");
		}
	}
	getch();
	return 0;
}
