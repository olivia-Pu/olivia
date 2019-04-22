#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	double s=0.0;                                                
    for(i=1;i<=100;i++)
    {
    	if(i%2!=0) 
		  s=s+1.0/i;
		else
		  s=s-1.0/i;	
	 }	    
    printf("%f",s);
	getch();
	return 0;
 } 
