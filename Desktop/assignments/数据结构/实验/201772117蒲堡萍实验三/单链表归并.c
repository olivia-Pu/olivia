#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1

typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode,*LinkList;

int main()
{
	LinkList a,b,c;
	LinkList Creat();
	void print(LinkList L);
	LinkList Merge(LinkList a,LinkList b);
	printf("���������� A��\n");
	a=Creat();
	printf("���������� B��\n");
	b=Creat();
	printf("\nLa�е�Ԫ�أ�"); 
	print(a);
	printf("\nLb�е�Ԫ�أ�"); 
	print(b);
	c=Merge(a,b);
	printf("\n�鲢���Ԫ�أ�");
	print(c); 
	return 0;
}

LinkList Creat()
{
	int n;
	LinkList L,p,r;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r=L;
    printf("���������������(��-1����)��\n");
    scanf("%d",&n);
    while(n!=-1)
    {
    	p=(LinkList)malloc(sizeof(LNode));
    	p->data=n;
    	p->next=NULL;
    	r->next=p;
    	r=p;
    	scanf("%d",&n);
	}
	 return L;
}

void print(LinkList L)
{
	LinkList p=L->next;
	while (p!=NULL)
	{
	    printf("%5d",p->data);
	    p=p->next;
	}
}

LinkList Merge(LinkList a,LinkList b)
{
	LinkList pa,pb,pc,c;
	pa=a->next;
	pb=b->next;
	c=pc=a;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(b);
	return (a);
}
