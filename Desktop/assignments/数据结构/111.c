#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MaxSize 20
typedef struct guest_info
{
	char name[10];
	int sum;
	char time[15];
	int number;
	struct guest_info *next;
}GuestLink,*Pointer;
void Insert(Pointer * Head);
void Search(Pointer  Head);
void Update(Pointer  Head);
void Delete(Pointer * Head);
void Show(Pointer  Head);
int main ()
{
	Pointer Head=NULL;
	int i;
	do
	{
		printf("\n=======ѡ��˵�=======\n\n");
		printf("1------����(Insert)\n");
		printf("2------��ѯ(Search)\n");
		printf("3------�޸�(Update)\n");
		printf("4------ɾ��(Delete)\n");
		printf("5------��ʾ(Show)\n");
		printf("6------�˳�(Exit)\n");
		printf("\n======================\n\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: Insert(&Head);
			       break;
			case 2: Search(Head);
			       break;
			case 3: Update(Head);
			       break;
			case 4: Delete(&Head);
			       break;
			case 5: Show(Head);
			       break;
			case 6: break;
			default: printf("����ѡ������ѡ");
			        break; 
		}
	}while(i!=6);
	 return 0;
}
void Insert(Pointer * Head)
{
	int in_number;
	Pointer p,q,r;
	printf("�������ţ�");
	scanf("%d",&in_number);
	p=q=*Head;
	while(p!=NULL)
	{
		if(p->number==in_number)
		{
			printf("�˱���Ѵ��ڣ�"); return;
		}
			else{ q=p;p=p->next;}
	}
		r=malloc(sizeof(GuestLink));
		r->next=NULL; 
		if(r==NULL)
		{
			printf("����ռ�ʧ�ܣ�"); return;
		}
		if(q==NULL)
		*Head=r;
		else {q->next=r;}
		r->number=in_number;
		printf("\n*********************\n\n");
		printf("����������:");
		scanf("%s",r->name);
		printf("����������:");
		scanf("%d",&r->sum);
		printf("�������ò�ʱ��:");
		scanf("%s",r->time); 
		printf("\n*********************\n\n");
		save();
}

void save( Pointer * Head)
{
	* Head;
	FILE *fp;
	int i;
	if((fp=fopen("cust.dat","wb"))==NULL)
	{
		printf("cannot open file\n");
		return ;
	}
	if(fwrite(* Head,sizeof (struct guest_info),1,fp)!=1)
	printf("file write error\n");
	fclose(fp);
}

void Search(Pointer  Head)
{
	int flag=1;
	int number;
	Pointer p;
	printf("��������Ҫ���ҵı��:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag)
	{
		if(p->number==number)
		{
			printf("\n*********************\n\n");
	        printf("����:%s",p->name);
		    printf("������:%d",p->sum);
	        printf("�ò�ʱ��:%s",p->time);
	        flag=0;
	        printf("\n*********************\n\n");
		}
		else p=p->next;
	}
	if(flag)
	printf("�ñ�Ų�����!!\n");
}

void Update(Pointer  Head)
{
	int flag=1;
	int number;
	Pointer p;
	printf("��������Ҫ�޸ĵı��:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag)
	{
		if(p->number==number)
		 {
		 	printf("\n*********************\n\n");
		     printf("����������:");
		     scanf("%d",p->sum);
	         printf("�������ò�ʱ��:");
		     scanf("%s",p->time); 
		     flag=0;
		    printf("\n*********************\n\n");
		 }
		 else p=p->next;
	}
	if(flag)
	printf("�ñ�Ų�����!!\n");
}

void Delete(Pointer * Head)
{
	 int flag=1;
	 int number;
	 Pointer p,q;
	 printf("��������Ҫɾ���ı�ţ�");
	 scanf("%d",&number);
	 p=q=*Head;
   	 while(p!=NULL&&flag)
     {
     	if(p->number==number)
     	{
     		if(p==*Head)
     		{*Head=p->next;free(p);}
			 else
			 {q->next=p->next;free(p);}
			 flag=0;
		 }
		 else
		 {q=p;p=p->next;}
	 }
	 if(flag)
	 printf("�ñ�Ų�����!!\n");
}


void Show(Pointer  Head)
{
	printf("       ================Ԥ������====================     \n\n");
	Pointer p;
	p=Head;
	while(p!=NULL)
	{
	    printf("����:%-10s",p->name);
		printf("������:%-10d",p->sum);
	    printf("�ò�ʱ��:%-10s",p->time);
	    printf("���:%-10d\n",p->number);
	    p=p->next;
	printf("\n      ===========================================      ");
	}
}

