#include <stdio.h> 
#include <math.h>
int main()
{   
    int f1=1,f2=1,f3,n,t;
    printf("%12d%12d",f1,f2);
    for(n=3;n<=20;n++)
    {
       f3=f1+f2;
       printf("%12d",f3);
       t=f1;
       f1=f2;
       f2=t+f2;
       if(n%4==0)
	      printf("\n"); 
	}
	getch();
	return 0;
}
