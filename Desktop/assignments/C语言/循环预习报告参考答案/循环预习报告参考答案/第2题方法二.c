#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	double s=0.0,k=1.0;                                                
    for(i=1;i<=100;i++)
    {
    	s=s+k/i;
    	k=-k; 	
	 }	    
    printf("%f",s);
	getch();
	return 0;
 } 
