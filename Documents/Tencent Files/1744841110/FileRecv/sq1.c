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
 sqlist L1;
 int i,k,data;
 k=InitList_Sq(&L1);//调用InitList_Sq实现顺序表的初始化 
 if(k==ERROR)
	{printf("顺序表初始化失败！");
	return 0;//退出程序
	}
 else
 	{printf("顺序表初始化成功！\n");
 	 printf("顺序表空间的起始地址为：%X\n",L1.elem);
 	 printf("顺序表的当前长度为：%d\n",L1.length);
 	 printf("顺序表的当前最大容量为：%d",L1.listsize);
	 }
 return 0;
}

int InitList_Sq(sqlist*L)
{L->elem=(int*)malloc(sizeof(int)*list_init_size);
return OK;
}
