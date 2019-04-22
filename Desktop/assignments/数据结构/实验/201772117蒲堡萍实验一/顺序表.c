 /*˳���*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define list_init_size 100
#define listincrement 10
#define OK 1
#define ERROR 0
typedef struct{
	int *elem;
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢���� 
}sqlist;

int main()
{ int InitList_Sq(sqlist *L); //��ʼ��˳��������� 
 int ListInsert_Sq(sqlist *L,int i,int e);//���뺯������ ��ʵ���ڵ�i��λ�ò���Ԫ��e 
 int ListDelete_Sq(sqlist *L,int i,int *e);//ɾ���������� 
 int LocateElem_Sq(sqlist *L,int e);//��ѯ��������������˳����е�һ����eֵ��ȵ�Ԫ�ص�λ��

sqlist L;
 int i,k,data;
 k=InitList_Sq(&L);//��ʼ��˳��� 
 if(k==ERROR)
{ printf("˳����ʼ��ʧ�ܣ�");
return 0;//�˳�����
} 
 printf("������5������");
 for(i=1;i<=5;i++)
 {	scanf("%d",&data); 
 	if(ListInsert_Sq(&L,i,data)==ERROR) {
 		printf("����λ�ò��Ϸ�");
 		break;
	 }
	 printf("%d ",L.elem[i-1]);
 }
 printf("\n");
 printf("������Ҫ�����λ�ã�");
 scanf("%d",&i); 
 printf("������Ҫ�����ֵ��");
 scanf("%d",&data); 
 printf("\n");
 if(ListInsert_Sq(&L,i,data)==ERROR) {
 		printf("����λ�ò��Ϸ�");} 
 else
 	{for(i=0;i<=L.length-1;i++)
 		printf("%d ",L.elem[i]);
	 }
 printf("\n");
 printf("������Ҫɾ��Ԫ�ص�λ�ã�");
 scanf("%d",&i); 
 if(ListDelete_Sq(&L,i,&data)==ERROR) {
 		printf("ɾ��λ�ò��Ϸ�");} 
 else
 	{for(i=0;i<=L.length-1;i++)
 		printf("%d ",L.elem[i]);
	 }
	 
printf("\n");
printf("������Ҫ��ѯ��Ԫ�أ�");
scanf("%d",&data); 
if(i=LocateElem_Sq(&L,data)) {
 		printf("��Ԫ�ص�λ��Ϊ��%d",i);} 
 else
 	printf("˳����в����ڸ�Ԫ��");	
 return 0;
}

int InitList_Sq(sqlist *L)
{
L->elem=(int *)malloc(list_init_size*sizeof(int));
if(!L->elem) exit(ERROR);
L->length=0;
L->listsize=list_init_size;
return OK;
}

int ListInsert_Sq(sqlist *L,int i,int e)
{ int newbase;
  int *q,*p;
	if(i<1||i>L->length+1) return ERROR;
	if(L->length>=L->listsize)
	{   int newbase;
		newbase=(int*)realloc(L->elem,(L->listsize+listincrement)*sizeof(int));
		if(!newbase) return ERROR;
		L->elem=newbase;
		L->listsize+=listincrement;
	}
	q=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);	p>=q; --p)*(p+1)=*p;
	*q=e;
	++L->length;
	return OK;
}


int ListDelete_Sq(sqlist *L,int i,int *e)
{
	int *q,*p;
	if((i<1)||(i>L->length)) return ERROR;
	p=&(L->elem[i-1]);
	e=*p;
	q=L->elem+L->length-1;
	for(++p;p<=q;++p)*(p-1)=*p;
	--L->length;
	return OK;
}

int LocateElem_Sq(sqlist *L,int e)
{
	int i=1,*p;
	p=L->elem;
	while(i<=L->length) ++i;
	if(strcmp(e,*p)==0) return i;
	else return ERROR;
      
}

