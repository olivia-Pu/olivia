#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MAXSIZE 20

typedef struct guest
{
	char name[10];//����
	char time[10];//�ò�ʱ��
	int sum;//�ò�������
	char tel[20];// �绰 
	char food[100]; //��Ʒ 
	int serv;   //�������  
	int num;//���
	struct guest *next;
}GuestLink,*Pointer;

void Insert(Pointer * Head);  //�������� 
void Search(Pointer  Head);
void Update(Pointer  Head);
void Delete(Pointer * Head);
void Show(Pointer  Head);
void save ();

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

//***********************************************************
void Insert(Pointer * Head)   //���뺯���Ķ��� 
{
	int in_number;
	Pointer p,q,r;     //�������� 
	printf("�������ţ�");
	scanf("%d",&in_number);
	p=q=*Head;  //Ѱ�ҷ��������ļ�¼ 
	while(p!=NULL)
	{
		if(p->num==in_number)
		{
			printf("�˱���Ѵ��ڣ�"); return;  
		}
			else{ q=p;p=p->next;} // ���η��� 
	}
		r=malloc(sizeof(GuestLink));  // ���봢��ռ� 
		r->next=NULL;  //����ָ���� 
		if(r==NULL)
		{
			printf("����ռ�ʧ�ܣ�"); return;
		}
		if(q==NULL)   // �ձ� 
		*Head=r;   //��ͷָ���½�� 
		else {q->next=r;}  //�ӱ�β������Ԫ�� 
		r->num=in_number;  //�������� 
		printf("\n         *************************************\n\n");
		printf("             ����������:");
		scanf("%s",r->name);
		printf("             ����������:");
		scanf("%d",&r->sum);
		printf("             �������ò�ʱ��:");
		scanf("%s",r->time); 
		printf("             ������绰����:");
		scanf("%s",r->tel); 
		printf("             �������Ʒ:");
		scanf("%s",r->food); 
		printf("             ������������(1/0):");
		scanf("%d",&r->serv); 
		printf("\n         *************************************\n\n");
}

void Search(Pointer  Head)   // ���Һ������� 
{
	int flag=1;  //��Ǳ��� 
	int number;
	Pointer p;
	printf("��������Ҫ���ҵı��:");
	scanf("%d",&number);
	p=Head;    //Ѱ�ҷ��������ļ�¼ 
	while(p!=NULL&&flag)
	{
		if(p->num==number)
		{
			printf("\n         *************************************\n\n");
	        printf("             ����:%s\n",p->name);
		    printf("             ����:%d\n",p->sum);
	        printf("             �ò�ʱ��:%s\n",p->time);
	        printf("             �绰����:%s\n",p->tel); 
	        printf("             ��Ʒ:%s\n",p->food); 
	        printf("             �������(1/0):%d\n",p->serv);
	        flag=0;  //��Ǳ��� 
	        printf("\n         *************************************\n\n");
		}
		else p=p->next;   //ָ�����κ��� 
	}
	if(flag)
	printf("�ñ�Ų�����!!\n");
}


void Update(Pointer  Head)  //�޸ĺ������� 
{
	int flag=1;  //��Ǳ��� 
	int number;
	Pointer p;
	printf("��������Ҫ�޸ĵı��:");
	scanf("%d",&number);
	p=Head;  //Ѱ�ҷ��������ļ�¼ 
	while(p!=NULL&&flag)
	{
		if(p->num==number) 
		 {
		 	printf("\n         *************************************\n\n");
		     printf("             ����������:");
		     scanf("%d",&p->sum);
	         printf("             �������ò�ʱ��:");
		     scanf("%s",p->time);
		     printf("             ������绰����:");
		     scanf("%s",p->tel); 
		     printf("             �������Ʒ:");
		     scanf("%s",p->food); 
		     printf("             ������������(1/0):");
		     scanf("%d",&p->serv); 
		     flag=0;  //��Ǳ��� 
		    printf("\n         *************************************\n\n");
		 }
		 else p=p->next;  //ָ�����κ��� 
	}
	if(flag)
	printf("�ñ�Ų�����!!\n");
}

void Delete(Pointer * Head)  //ɾ���������� 
{
	 int flag=1;
	 int number;
	 Pointer p,q;  //����˵�� 
	 printf("��������Ҫɾ���ı�ţ�");
	 scanf("%d",&number);
	 p=q=*Head;   //Ѱ�ҷ��������ļ�¼ 
   	 while(p!=NULL&&flag)
     {
     	if(p->num==number)
     	{
     		if(p==*Head)    //ɾ����ͷԪ�� 
     		{
			     *Head=p->next;
			     free(p);
			}
			 else
			{
			     q->next=p->next;   //ɾ������Ԫ��
				 free(p);
			}    
			 flag=0;
		 }
		 else
		 {q=p;p=p->next;}  //ָ����ƣ�q���Ϊp����ǰ�� 
	 }
	 if(flag)
	 printf("�ñ�Ų�����!!\n");
}


void Show(Pointer  Head)   //��ʾ�����Ķ��� 
{
	printf("            ============================Ԥ������===============================     \n\n");
	Pointer p;
	int i=0;   //�������� 
	p=Head;
	while(p!=NULL)
	{   
	    printf("����:%-10s",p->name);
		printf("����:%-5d",p->sum);
	    printf("�ò�ʱ��:%-8s",p->time);
	    printf("�绰:%-20s",p->tel);
	    printf("�������(1/0):%-5d",p->serv);
	    printf("���:%-4d\n",p->num);
	    printf("��Ʒ:%-100s",p->food);
	    printf("\n");
	    p=p->next;++i;
	}
	printf("\n�ͻ�������:%d\n",i);
	printf("\n            ===================================================================      ");
}
