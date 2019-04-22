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
		printf("\n=======选择菜单=======\n\n");
		printf("1------插入(Insert)\n");
		printf("2------查询(Search)\n");
		printf("3------修改(Update)\n");
		printf("4------删除(Delete)\n");
		printf("5------显示(Show)\n");
		printf("6------退出(Exit)\n");
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
			default: printf("错误选择！请重选");
			        break; 
		}
	}while(i!=6);
	 return 0;
}
void Insert(Pointer * Head)
{
	int in_number;
	Pointer p,q,r;
	printf("请输入编号：");
	scanf("%d",&in_number);
	p=q=*Head;
	while(p!=NULL)
	{
		if(p->number==in_number)
		{
			printf("此编号已存在！"); return;
		}
			else{ q=p;p=p->next;}
	}
		r=malloc(sizeof(GuestLink));
		r->next=NULL; 
		if(r==NULL)
		{
			printf("分配空间失败！"); return;
		}
		if(q==NULL)
		*Head=r;
		else {q->next=r;}
		r->number=in_number;
		printf("\n*********************\n\n");
		printf("请输入姓名:");
		scanf("%s",r->name);
		printf("请输入人数:");
		scanf("%d",&r->sum);
		printf("请输入用餐时间:");
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
	printf("请输入需要查找的编号:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag)
	{
		if(p->number==number)
		{
			printf("\n*********************\n\n");
	        printf("姓名:%s",p->name);
		    printf("请人数:%d",p->sum);
	        printf("用餐时间:%s",p->time);
	        flag=0;
	        printf("\n*********************\n\n");
		}
		else p=p->next;
	}
	if(flag)
	printf("该编号不存在!!\n");
}

void Update(Pointer  Head)
{
	int flag=1;
	int number;
	Pointer p;
	printf("请输入需要修改的编号:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag)
	{
		if(p->number==number)
		 {
		 	printf("\n*********************\n\n");
		     printf("请输入人数:");
		     scanf("%d",p->sum);
	         printf("请输入用餐时间:");
		     scanf("%s",p->time); 
		     flag=0;
		    printf("\n*********************\n\n");
		 }
		 else p=p->next;
	}
	if(flag)
	printf("该编号不存在!!\n");
}

void Delete(Pointer * Head)
{
	 int flag=1;
	 int number;
	 Pointer p,q;
	 printf("请输入需要删除的编号：");
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
	 printf("该编号不存在!!\n");
}


void Show(Pointer  Head)
{
	printf("       ================预订名单====================     \n\n");
	Pointer p;
	p=Head;
	while(p!=NULL)
	{
	    printf("姓名:%-10s",p->name);
		printf("请人数:%-10d",p->sum);
	    printf("用餐时间:%-10s",p->time);
	    printf("编号:%-10d\n",p->number);
	    p=p->next;
	printf("\n      ===========================================      ");
	}
}

