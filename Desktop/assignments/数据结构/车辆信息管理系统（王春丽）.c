#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define list_init_size 100  //����100����λ���� 
#define listincrement 10
#define OK 1
#define ERROR 0

typedef struct car
{
	
	char tag[5];   //���in ��in��ʾ��λ�г� 
	char carnum[20];//���ƺ� 
	int num;      // ��ų�λ 
	char name[20];  //�������� 
	char tele[20];  //Ų���绰 
	float date;     //ͣ������ 
}car;

typedef struct{
	car *elem;
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢���� 
}sqlist;

int main()
{
    int InitList_Sq(sqlist *L); //��ʼ��˳��������� 
    void CreteList_Sq(sqlist *L); //������Ϣ¼�뺯������ 
	void Listfind_Sq(sqlist *L,int a); //ͨ����λ����ѯ�йس�����Ϣ�������� 
    void Listfond_Sq(sqlist *L,char n[]);//������������ѯ�йس�����Ϣ��������
	void Listfind_L(sqlist *L,char m[]);//ͨ��Ų���绰����ѯ�йس�����Ϣ��������
	void Listout_L(sqlist *L); //��ʾ��ǰ��վ���г�����Ϣ�������� 
	void Listfind_Ln(sqlist *L,int h);//��ѯĳ����λ�Ƿ��г���������
	int CurrentCarSpaces(sqlist *L); //���塰��ʾ��ǰ��λ�������������ĺ���
	void Today_Count(sqlist *L,float k);//��ѯĳ���վ�������� 
	void menu();//��ʾ�˵��������� 
	
	
    sqlist L1;
    int i,k,date,b,p,e;
    float t;
    p=0;
    char name[20];
	char tele[20];
    k=InitList_Sq(&L1);//����InitList_Sqʵ�ֳ�����Ϣ��ĳ�ʼ�� 
    if(k==ERROR)
    	{
		printf("������Ϣ���ʼ��ʧ�ܣ�");
    	return 0;//�˳�����
    	}
    while(p==0) 
    {
       menu();
       printf("\n��ѡ���ܣ�");
	   scanf("%d",&e);
	   
	   if(e==1)
		{
		 CreteList_Sq(&L1);//������Ϣ¼�� 
		}
		
        if(e==2)
         {
           printf("\n������������ѯ�йس�����Ϣ"); //������������ѯ�йس�����Ϣ
           printf("\n������Ҫ��ѯ�ĳ���������");
           scanf("%s",name);
           Listfond_Sq(&L1,name);
         }
         
        if(e==3)
         {
           printf("\n��Ų���绰��ѯ�йس�����Ϣ"); //ͨ��Ų���绰����ѯ�йس�����Ϣ
           printf("\n������Ų���绰��");
           scanf("%s",tele);
           Listfind_L(&L1,tele);
         }
         
        if(e==4)
         {
           printf("\n��ʾ��ǰվ�����г�����Ϣ��") ; //��ʾ��ǰվ�����г�����Ϣ
           Listout_L(&L1) ;
         }  
        if(e==5) 
        {
	       printf("�����복λ�ţ�");  //��ѯĳ����λ�Ƿ��г� 
	       scanf("%d",&b) ;
	       Listfind_Ln(&L1,b);
    	} 
    	if(e==7)
    	{
    		CurrentCarSpaces(&L1);//��ʾ��ǰ��λ���������� 
		}
		
		 if(e==6)
	    {
          printf("\n����λ��ѯ�йس�����Ϣ"); //����λ��ѯ�йس�����Ϣ
          printf("\n������Ҫ��ѯ�ĳ�λ�ţ�");
          scanf("%d",&i);
          Listfind_Sq(&L1,i);
         }
		if(e==8)
		{ 
		    printf("������Ҫ��ѯ������:");
	        scanf("%f",&t);
			Today_Count(&L1,t);//��ѯĳ���վ��������
		 } 
		if(e==0) 
		  break;
    }
 return 0;
}

void menu() 
  {
  	printf("\n");
	printf("\n**************��ӭʹ��У԰������Ϣ����ϵͳ**************\n");
    printf("\t*******��ѡ�����б�*******\n"); 
	printf("\t\t1.������Ϣ¼��\n");
	printf("\t\t2.������������ѯ�йس�����Ϣ\n");
	printf("\t\t3.ͨ��Ų���绰����ѯ�йس�����Ϣ\n");
	printf("\t\t4.��ʾ��ǰվ�����г�����Ϣ\n");
	printf("\t\t5.��ѯĳ����λ�Ƿ��г�\n");
	printf("\t\t6.����λ��ѯ�йس�����Ϣ\n");
	printf("\t\t7.��ѯ��ǰ��λ����������\n");
	printf("\t\t8.��ʾĳ���վ�ĳ�������\n");
	printf("\t\t0.�˳�ϵͳ\n");
 }
 
int InitList_Sq(sqlist *L)  //˳����ʼ�� 
{
	L->elem=(car *)malloc(sizeof(car)*list_init_size);
	if(L->elem==NULL)
	   return ERROR;
	L->length=0;
	L->listsize=list_init_size;
	return OK; 
}

void CreteList_Sq(sqlist *L)  //������Ϣ¼��
 {
    int i,e;
    i=0;
    e=0;
    for(;i<=L->listsize-1,e==0;i++)
 	   {   
 		 
		printf("\n�����복���ģ���־ ���ƺ� ��λ �������� Ų���绰 ���� ��");
		scanf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,&L->elem[i].num,L->elem[i].name,L->elem[i].tele,&L->elem[i].date);
		L->length=L->length+1;
		printf("�Ƿ������Ϣ¼�룿1/0��");//�� 0�ͼ���¼�룬�� 1�ͽ���¼�� 
		scanf("%d",&e);	 
	   }
 }
 
void Listfond_Sq(sqlist *L,char n[]) //������������ѯ�йس�����Ϣ����
{
	int i;
		for(i=0;i<=L->length-1;i++)
		{
		
			if(strcmp(L->elem[i].name,n)==0)
			  {
			  	printf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,L->elem[i].num,L->elem[i].name,L->elem[i].tele,L->elem[i].date);
	            break;
			  }
			if(i>L->length-1)
			  printf("���복����������"); 
		}
}

void Listfind_Sq(sqlist *L,int a) //ͨ����λ����ѯ��Ϣ����
{
	int i;
	for(i=0;i<=L->length-1;i++)
	  {
	  	if(L->elem[i].num==a)
	  	  {
			printf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,L->elem[i].num,L->elem[i].name,L->elem[i].tele,L->elem[i].date);
	        break;
		  }
	  }
	 if(i>L->length-1)
	   printf("��λû�г���"); 
}

void Listfind_L(sqlist *L,char m[]) //ͨ��Ų���绰����ѯ�йس�����Ϣ��������
{
	int i;
		for(i=0;i<=L->length-1;i++)
		{
			if(strcmp(L->elem[i].tele ,m)==0)
			  {
			  	printf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,L->elem[i].num,L->elem[i].name,L->elem[i].tele,L->elem[i].date);
	            break;
			  }
			if(i>L->length-1)
			  printf("����Ų���绰����"); 
		}
} 
	
void Listout_L(sqlist *L)  //��ʾ��ǰ��վ���г�����Ϣ����
{
	int i;
	char m[5]={"in"};
	for(i=0;i<=L->length-1;i++)
	{
		if(strcmp(L->elem[i].tag ,m)==0)
		printf("\n");
		printf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,L->elem[i].num,L->elem[i].name,L->elem[i].tele,L->elem[i].date);
	}
}

void Listfind_Ln(sqlist *L,int h) //��ѯĳ����λ�Ƿ��г�����
{
	char m[5]={"in"};
	if(strcmp(L->elem[h].tag,m)==0)
	  printf("�г���"); 
	else
	  printf("�޳���"); 
}

int CurrentCarSpaces(sqlist *L) //����һ������ʾ��ǰ��λ�������������ĺ��� 
{
	int Find_IN(sqlist *L);  //���� 
	int IN;  //IN���ڴ�ŵ�ǰ��λ����
	int OUT; //OUT���ڴ�ŵ�ǰ��λʣ���� 
	
	IN=Find_IN(L);  // IN ��ֵ��Ϊcount1���ظ� Find_IN(sqlist *L)��ֵ 
	OUT=L->listsize-IN; 
	
	printf("��ǰ��λ������%d\n",IN);
	printf("��ǰ��λ������%d\n",OUT);

}

int Find_IN(sqlist *L)  //�Զ���IN������������ L�в����ַ� in������������ָ��� 
{
	char o[]="in"; //�����������ַ���in�� 
	int i;
	int count1=0;

	for(i=0;i<=L->length-1;i++)
	{
      if(strcmp(L->elem[i].tag,o)==0) //�ȽϺ��� if(strcmp(string1, string2) == 0)
	  count1++;
    }
 	return count1;  //count1��ֵ���ظ� Find_IN(sqlist *L)
}


void Today_Count(sqlist *L,float k)//��ѯĳ���վ�������� 
{
	int i,sum;
	sum=0;
	for(i=0;i<=L->length-1;i++)
	{
		if(L->elem[i].date==k) 
		sum=sum+1;
	}
	printf(" %d\n",sum);
}
