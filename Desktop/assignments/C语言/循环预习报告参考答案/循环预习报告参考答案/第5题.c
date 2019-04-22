#include <stdio.h>
#include <math.h>
int main()
{
	int i,s=0;                                            
    for(i=1;i<=100;i++)
    {
    	if(i%7==0)
    	 s=s+i;	  
	 }	
	 printf("%d",s);    
	getchar();
	return 0;
 } 
