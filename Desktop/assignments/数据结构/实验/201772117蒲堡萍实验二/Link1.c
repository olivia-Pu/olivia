#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
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
	LinkList head,p;       //����һ��ָ��ṹ���ָ��head��Ϊ�������ͷָ�� 
	char n[6];
	printf("��β�巨������ͷ���ĵ�����ѧ���ɼ�����\n");
	head=CreateList_L();  //������ͷ���ĵ�����headΪ��ͷָ��
	Print_L(head);      //��������������Ԫ��
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
