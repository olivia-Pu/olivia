#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Student)
struct Student
{
	long num;
	float score;
	struct Student *next;
 };
 int n;
 struct Student *creat()
 {
 	struct Student *head;
 	struct Student *p1,*p2;
 	n=0;
 	p1=p2=(struct Student *)malloc(LEN);
 	scanf("%ld,%f",&p1->num,&p1->score);
 	head=NULL;
 	while(p1->num!=0)
 	{
 		n=n+1;
 		if(n==1) head=p1;
 		else p2->next=p1;
 		p2=p1;
 		p1=(struct Student *)malloc(LEN);
		scanf("%ld,%f",&p1->num,&p1->score);
	 }
	 p2->next=NULL;
	 return(head);
 }
 
 void print(struct Student *head)
 {
 	struct Student *p;
 	printf("\nNow,These %d record are:\n",n);
 	p=head;
 	if(head!=NULL);
 	 do
 	   {
 	   	    printf("%ld%5.1f\n",p->num,p->score);
 	   	    p=p->next;
	    }
	    while(p!=NULL);
  } 

void main()
{
	struct Student *head;
	head=creat();
	print(head);
}
