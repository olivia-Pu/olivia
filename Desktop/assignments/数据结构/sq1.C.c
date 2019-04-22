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
		printf("初始化分配失败！");
		return 0; 
	}
	else 
	{printf("顺序表初始化成功！\n");
 	 printf("顺序表空间的起始地址为：%X\n",L1.elem);
 	 printf("顺序表的当前长度为：%d\n",L1.length);
 	 printf("顺序表的当前最大容量为：%d",L1.listsize);
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

