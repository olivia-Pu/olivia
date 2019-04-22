#include <stdio.h>
#include <math.h>
int main()
{
	int i,a,b,c,d;                                            
    for(i=1000;i<=9999;i++)
    {
    	a=i/1000;
    	b=(i/1000)%100;
    	c=(i/100)%10;
    	d=i%10;
		if(i==pow(a,4)+pow(b,4)+pow(c,4)+pow(c,4)) 
		  printf("%5d",i);  
	}	 
	getchar();
	return 0;
 } 
