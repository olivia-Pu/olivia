#include<stdio.h>
#include<stdlib.h>
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
{int InitList_Sq(sqlist *L); //初始化顺序表函数声明 
 int ListInsert_Sq(sqlist *L,int i,int e);//插入函数声明 ，实现在第i个位置插入元素e
 int ListDelete_Sq(sqlist *L,int i,int *e);//删除函数声明
 int LocateElem_Sq(sqlist *L,int e);//查询函数声明，返回顺序表中第一个与e值相等的元素的位序
 sqlist L1;
 int i,k,data;
 k=InitList_Sq(&L1);//调用InitList_Sq实现顺序表的初始化 
 if(k==ERROR)
	printf("顺序表初始化失败！");
 else
 	{printf("顺序表初始化成功！\n");
 	 printf("顺序表空间的起始地址为：%X\n",L1.elem);
 	 printf("顺序表的当前长度为：%d\n",L1.length);
 	 printf("顺序表的当前最大容量为：%d",L1.listsize);
	 }
 printf("\n请输入5个数：");
 for(i=1;i<=5;i++)//调用 ListInsert_Sq函数将输入的5个元素插入到顺序表L1中 
 {	scanf("%d",&data); 
 	if(ListInsert_Sq(&L1,i,data)==ERROR) {
 		printf("插入位置不合法");
 		break;
	 }
	 printf("%d ",L1.elem[i-1]);
 }
 printf("\n请输入要插入的位置：");
 scanf("%d",&i); 
 printf("请输入要插入的值：");
 scanf("%d",&data); 
 printf("\n");
 if(ListInsert_Sq(&L1,i,data)==ERROR) //将data插入到顺序表L1的第i个位置上 
 		printf("插入位置不合法");
 else
 	{for(i=0;i<=L1.length-1;i++)
 		printf("%d ",L1.elem[i]);
	 }
 printf("\n请输入要删除元素的位置：");
 scanf("%d",&i); 
 if(ListDelete_Sq(&L1,i,&data)==ERROR) //调用ListDelete_Sq函数实现删除顺序表L1中第i个位置的元素 
 		printf("删除位置不合法");
 else
 	{for(i=0;i<=L1.length-1;i++) //删除成功，输出顺序表L1的所有元素 
 		printf("%d ",L1.elem[i]);
	 }
 printf("\n请输入要查询的元素：");
 scanf("%d",&data); 
 if(i=LocateElem_Sq(&L1,data)) //调用LocateElem_Sq函数，返回data元素在L1中的位序 
 		printf("该元素的位置为：%d",i);
 else
 	printf("顺序表中不存在该元素");
 return 0;//退出程序
}

int InitList_Sq(sqlist*L)
{L->elem=(int*)malloc(sizeof(int)*list_init_size);
return OK;
}

int ListInsert_Sq(sqlist *L,int i,int e)
{
int *p,*q;//q指向插入位置元素，p指向最后一个元素
if(i<1||i>L->length+1) return ERROR;
if(L->length>=L->listsize)
   {
   	realloc(L->elem,sizeof(int)*(L->length+listincrement));
   	L->listsize=L->listsize+listincrement;
	} 
q=&L->elem[i-1];
for(p=&L->elem[L->length-1];p>=q;p--)
    *(p+1)=*p;
	*q=e;
	L->length++;
	return OK;
}

int ListDelete_Sq(sqlist *L,int i,int *e)
{
int *p,*q;//P为删除元素位置 ,q指向表尾 
if(i<1||i>L->length) return ERROR;
p=&(L->elem[i-1]);
*e=*p;
q=L->elem+L->length-1;
for(++p;p<=q;++p) *(p-1)=*p;
L->length--;
return OK;	
}

int LocateElem_Sq(sqlist *L,int e)
{
int *p;
int i=1;
p=L->elem;
while(i<=L->length&&*p++!=e) ++i;
if(i<=L->length) return i;
else return 0; 
} 
