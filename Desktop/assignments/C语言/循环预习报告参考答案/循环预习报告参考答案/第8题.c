#include <stdio.h>
#include <math.h>
int main()
{
	int i,a,b,c;                                            
    for(i=100;i<=999;i++)
    {
    	a=i/100;
    	b=(i/10)%10;
    	c=i%10;
		if(i==pow(a,3)+pow(b,3)+pow(c,3)) 
		  printf("%5d",i);  
	}	 
	getchar();
	return 0;
 } 
