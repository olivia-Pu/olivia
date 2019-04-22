#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct LNode{
	char num[6];      //结点的数据域 
	char name[20];    //结点的数据域 
	int score;        //结点的数据域
	struct LNode * next;     //结点的指针域 
}LNode,* LinkList;

int main()
{
	LinkList CreateList_L( ); 
	void Print_L(LinkList L); 
	int ListInsert_L(LinkList L,int i);
	int ListInsert_L(LinkList L,int i); 
	LinkList head,p;       //定义一个指向结构体的指针head作为单链表的头指针 
	char n[6];
	printf("用尾插法建立带头结点的单链表（学生成绩链表）\n");
	head=CreateList_L();  //创建带头结点的单链表，head为其头指针
	Print_L(head);      //输出单链表的所有元素
	printf("\n在第2个位置插入一个新的结点\n"); 
	if(ListInsert_L(head,2)==ERROR)
		printf("插入位置不合法");
	else
		Print_L(head);
		printf("\n删除第2个结点\n"); 
	if(ListDelete_L(head,2)==ERROR)
		printf("删除位置不合法");
	else
		Print_L(head);
	return 0;
 } 
 
 LinkList CreateList_L( )  //尾插法建立带头结点的单链表 
 {
 	LinkList L,p,r;
 	int flag=0;
 	L=(LinkList)malloc(sizeof(LNode));
 	L->next=NULL;  //建立一个带头结点的空链表 
    r=L;
    while(flag==0)
    {
    	p=(LinkList)malloc(sizeof(LNode));
    	printf("输入学生的学号 姓名 成绩:");
    	scanf("%s%s%d",p->num,p->name,&p->score);
    	p->next=NULL; 
    	r->next=p;
    	r=p;
    	printf("是否结束创建？1/0:");
    	scanf("%d",&flag);
	}
	return L;
 }
void Print_L(LinkList L)
{
	LinkList p;
	p=L->next;
	printf("NUM   NAME      SCORE\n");
	while(p!=NULL)
	{
		printf("%-6s%-10s%-5d\n",p->num,p->name,p->score);
		p=p->next;
	}
 } 
 
int ListInsert_L(LinkList L,int i)  //在成绩链表的第i个位置插入新的结点
{   
    LinkList p,S;
    int j;
	p=L;j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
	return ERROR;
	S=(LinkList)malloc(sizeof(LNode));
	printf("请输入要插入学生的学号 姓名 成绩:");
    scanf("%s%s%d",S->num,S->name,&S->score);
	S->next=p->next;
	p->next=S;
	return OK;
}

int ListDelete_L(LinkList L,int i)  //删除第i个位置的结点
{
	LinkList p,q;
	int j;
	p=L;j=0;
	while (p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)
	return ERROR;
	q=p->next;
	p->next=q->next;
	free(q);
 } 
