 /*顺序表*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define list_init_size 100
#define listincrement 10
#define OK 1
#define ERROR 0
typedef struct{
	int *elem;
	int length;//当前长度 
	int listsize;//当前分配的存储容量 
}sqlist;

int main()
{ int InitList_Sq(sqlist *L); //初始化顺序表函数声明 
 int ListInsert_Sq(sqlist *L,int i,int e);//插入函数声明 ，实现在第i个位置插入元素e 
 int ListDelete_Sq(sqlist *L,int i,int *e);//删除函数声明 
 int LocateElem_Sq(sqlist *L,int e);//查询函数声明，返回顺序表中第一个与e值相等的元素的位序

sqlist L;
 int i,k,data;
 k=InitList_Sq(&L);//初始化顺序表 
 if(k==ERROR)
{ printf("顺序表初始化失败！");
return 0;//退出程序
} 
 printf("请输入5个数：");
 for(i=1;i<=5;i++)
 {	scanf("%d",&data); 
 	if(ListInsert_Sq(&L,i,data)==ERROR) {
 		printf("插入位置不合法");
 		break;
	 }
	 printf("%d ",L.elem[i-1]);
 }
 printf("\n");
 printf("请输入要插入的位置：");
 scanf("%d",&i); 
 printf("请输入要插入的值：");
 scanf("%d",&data); 
 printf("\n");
 if(ListInsert_Sq(&L,i,data)==ERROR) {
 		printf("插入位置不合法");} 
 else
 	{for(i=0;i<=L.length-1;i++)
 		printf("%d ",L.elem[i]);
	 }
 printf("\n");
 printf("请输入要删除元素的位置：");
 scanf("%d",&i); 
 if(ListDelete_Sq(&L,i,&data)==ERROR) {
 		printf("删除位置不合法");} 
 else
 	{for(i=0;i<=L.length-1;i++)
 		printf("%d ",L.elem[i]);
	 }
	 
printf("\n");
printf("请输入要查询的元素：");
scanf("%d",&data); 
if(i=LocateElem_Sq(&L,data)) {
 		printf("该元素的位置为：%d",i);} 
 else
 	printf("顺序表中不存在该元素");	
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

