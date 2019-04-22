#include<stdio.h>
#include<string.h>
#include"stdlib.h"
#define MAXSIZE 20

void Insert(Pointer * Head);  //�������� 
void Search(Pointer  Head);
void Update(Pointer  Head);
void Delete(Pointer * Head);
void Show(Pointer  Head);

struct guest
{
	char name[10];//����
	char time[10];//�ò�ʱ��
	int sum;//�ò�������
	char tel[20];// �绰 
	char food[100]; //��Ʒ 
	int serv;   //�������  
	int num;//���
	struct guest *next;
}GuestList[MAXSIZE],*Pointer;

//***********************main()****************************
int main()
{
	Pointer Head=NULL;  // ͷָ�� 
	int i;
	do
	{
		printf("\n\n           ==============ѡ��˵�=============\n\n");   
		printf("            *   1------���û����(Insert)  *\n");
		printf("            *   2------�û���ѯ(Search)    *\n");
		printf("            *   3------�û��޸�(Update)    *\n");
		printf("            *   4------�û�ɾ��(Delete)    *\n");
		printf("            *   5------�û���ʾ(Show)      *\n");
		printf("            *   6------�˳�(Exit)          *\n");
		printf("\n           ====================================\n\n");

		scanf("%d",&i);//�����û���ѡ��

		switch(i)    // �������ָ��� 
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
			default: printf("����ѡ������ѡ");
			        break; 
		}
	}while(i!=6);

	return 0;
}
//***********************************************************

