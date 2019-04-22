#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
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
	LinkList head,p;       //定义一个指向结构体的指针head作为单链表的头指针 
	char n[6];
	printf("用尾插法建立带头结点的单链表（学生成绩链表）\n");
	head=CreateList_L();  //创建带头结点的单链表，head为其头指针
	Print_L(head);      //输出单链表的所有元素
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
