#include <stdio.h>
#include <math.h>
int main()
{
	int i,k=0;                                            
    for(i=1;i<=100;i++)
    {
    	if(i%7!=0)
    	{
    	  printf("%5d",i);
		  k=k+1;
		  if(k%7==0)
		     printf("\n");
		}	  
	 }	    
	getchar();
	return 0;
 } 
