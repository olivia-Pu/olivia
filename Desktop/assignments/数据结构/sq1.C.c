#include <stdio.h>
#include <stdlib.h>
#define list_init_size 100
#define listincrement 10
#define OK 1
#define ERROR 0

typedef struct
{
	int *elem;
	int  length;
	int  listsize;
} sqlist;

int main ()
{
	int initlist_sq(sqlist *L);
	sqlist L1;
	int i,k,data;
	k=initlist_sq(&L1);
	if(k==ERROR)
	{
		printf("��ʼ������ʧ�ܣ�");
		return 0; 
	}
	else 
	{printf("˳����ʼ���ɹ���\n");
 	 printf("˳���ռ����ʼ��ַΪ��%X\n",L1.elem);
 	 printf("˳���ĵ�ǰ����Ϊ��%d\n",L1.length);
 	 printf("˳���ĵ�ǰ�������Ϊ��%d",L1.listsize);
	 }
	 return 0;
}
int initlist_sq(sqlist *L)
{	
    L->elem=(int *)malloc(sizeof(int)*list_init_size);
    if(!L->elem) return ERROR;
    L->length=0;
    L->listsize=list_init_size;
    return OK;
}

