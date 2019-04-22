#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct LNode{
	char num[6];      //���������� 
	char name[20];    //���������� 
	int score;        //����������
	struct LNode * next;     //����ָ���� 
}LNode,* LinkList;

int main()
{
	LinkList CreateList_L( ); 
	void Print_L(LinkList L); 
	int ListInsert_L(LinkList L,int i);
	int ListInsert_L(LinkList L,int i); 
	LinkList head,p;       //����һ��ָ��ṹ���ָ��head��Ϊ�������ͷָ�� 
	char n[6];
	printf("��β�巨������ͷ���ĵ�����ѧ���ɼ�����\n");
	head=CreateList_L();  //������ͷ���ĵ�����headΪ��ͷָ��
	Print_L(head);      //��������������Ԫ��
	printf("\n�ڵ�2��λ�ò���һ���µĽ��\n"); 
	if(ListInsert_L(head,2)==ERROR)
		printf("����λ�ò��Ϸ�");
	else
		Print_L(head);
		printf("\nɾ����2�����\n"); 
	if(ListDelete_L(head,2)==ERROR)
		printf("ɾ��λ�ò��Ϸ�");
	else
		Print_L(head);
	return 0;
 } 
 
 LinkList CreateList_L( )  //β�巨������ͷ���ĵ����� 
 {
 	LinkList L,p,r;
 	int flag=0;
 	L=(LinkList)malloc(sizeof(LNode));
 	L->next=NULL;  //����һ����ͷ���Ŀ����� 
    r=L;
    while(flag==0)
    {
    	p=(LinkList)malloc(sizeof(LNode));
    	printf("����ѧ����ѧ�� ���� �ɼ�:");
    	scanf("%s%s%d",p->num,p->name,&p->score);
    	p->next=NULL; 
    	r->next=p;
    	r=p;
    	printf("�Ƿ����������1/0:");
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
 
int ListInsert_L(LinkList L,int i)  //�ڳɼ�����ĵ�i��λ�ò����µĽ��
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
	printf("������Ҫ����ѧ����ѧ�� ���� �ɼ�:");
    scanf("%s%s%d",S->num,S->name,&S->score);
	S->next=p->next;
	p->next=S;
	return OK;
}

int ListDelete_L(LinkList L,int i)  //ɾ����i��λ�õĽ��
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
