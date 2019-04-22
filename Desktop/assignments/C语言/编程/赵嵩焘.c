#include<stdio.h>
#include<string.h>
#include"stdlib.h"
#define MAXSIZE 20

void Insert(Pointer * Head);  //函数声明 
void Search(Pointer  Head);
void Update(Pointer  Head);
void Delete(Pointer * Head);
void Show(Pointer  Head);

struct guest
{
	char name[10];//姓名
	char time[10];//用餐时间
	int sum;//用餐总人数
	char tel[20];// 电话 
	char food[100]; //菜品 
	int serv;   //包房与否  
	int num;//编号
	struct guest *next;
}GuestList[MAXSIZE],*Pointer;

//***********************main()****************************
int main()
{
	Pointer Head=NULL;  // 头指针 
	int i;
	do
	{
		printf("\n\n           ==============选择菜单=============\n\n");   
		printf("            *   1------新用户添加(Insert)  *\n");
		printf("            *   2------用户查询(Search)    *\n");
		printf("            *   3------用户修改(Update)    *\n");
		printf("            *   4------用户删除(Delete)    *\n");
		printf("            *   5------用户显示(Show)      *\n");
		printf("            *   6------退出(Exit)          *\n");
		printf("\n           ====================================\n\n");

		scanf("%d",&i);//接收用户的选择

		switch(i)    // 调用相关指令函数 
		{
			case 1: Insert(&Head);
			       break;
			case 2: Search(Head);
			       break;
			case 3: Update(Head);
			       break;
			case 4: Delete(&Head);
			       break;
			case 5: Show(Head);
			       break;
			case 6: break;
			default: printf("错误选择！请重选");
			        break; 
		}
	}while(i!=6);

	return 0;
}
//***********************************************************

