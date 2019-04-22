#include<stdio.h>
#include<stdlib.h>
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
{int InitList_Sq(sqlist *L); //��ʼ��˳��������� 
 int ListInsert_Sq(sqlist *L,int i,int e);//���뺯������ ��ʵ���ڵ�i��λ�ò���Ԫ��e
 int ListDelete_Sq(sqlist *L,int i,int *e);//ɾ����������
 int LocateElem_Sq(sqlist *L,int e);//��ѯ��������������˳����е�һ����eֵ��ȵ�Ԫ�ص�λ��
 sqlist L1;
 int i,k,data;
 k=InitList_Sq(&L1);//����InitList_Sqʵ��˳���ĳ�ʼ�� 
 if(k==ERROR)
	printf("˳����ʼ��ʧ�ܣ�");
 else
 	{printf("˳����ʼ���ɹ���\n");
 	 printf("˳���ռ����ʼ��ַΪ��%X\n",L1.elem);
 	 printf("˳���ĵ�ǰ����Ϊ��%d\n",L1.length);
 	 printf("˳���ĵ�ǰ�������Ϊ��%d",L1.listsize);
	 }
 printf("\n������5������");
 for(i=1;i<=5;i++)//���� ListInsert_Sq�����������5��Ԫ�ز��뵽˳���L1�� 
 {	scanf("%d",&data); 
 	if(ListInsert_Sq(&L1,i,data)==ERROR) {
 		printf("����λ�ò��Ϸ�");
 		break;
	 }
	 printf("%d ",L1.elem[i-1]);
 }
 printf("\n������Ҫ�����λ�ã�");
 scanf("%d",&i); 
 printf("������Ҫ�����ֵ��");
 scanf("%d",&data); 
 printf("\n");
 if(ListInsert_Sq(&L1,i,data)==ERROR) //��data���뵽˳���L1�ĵ�i��λ���� 
 		printf("����λ�ò��Ϸ�");
 else
 	{for(i=0;i<=L1.length-1;i++)
 		printf("%d ",L1.elem[i]);
	 }
 printf("\n������Ҫɾ��Ԫ�ص�λ�ã�");
 scanf("%d",&i); 
 if(ListDelete_Sq(&L1,i,&data)==ERROR) //����ListDelete_Sq����ʵ��ɾ��˳���L1�е�i��λ�õ�Ԫ�� 
 		printf("ɾ��λ�ò��Ϸ�");
 else
 	{for(i=0;i<=L1.length-1;i++) //ɾ���ɹ������˳���L1������Ԫ�� 
 		printf("%d ",L1.elem[i]);
	 }
 printf("\n������Ҫ��ѯ��Ԫ�أ�");
 scanf("%d",&data); 
 if(i=LocateElem_Sq(&L1,data)) //����LocateElem_Sq����������dataԪ����L1�е�λ�� 
 		printf("��Ԫ�ص�λ��Ϊ��%d",i);
 else
 	printf("˳����в����ڸ�Ԫ��");
 return 0;//�˳�����
}

int InitList_Sq(sqlist*L)
{L->elem=(int*)malloc(sizeof(int)*list_init_size);
return OK;
}

int ListInsert_Sq(sqlist *L,int i,int e)
{
int *p,*q;//qָ�����λ��Ԫ�أ�pָ�����һ��Ԫ��
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
int *p,*q;//PΪɾ��Ԫ��λ�� ,qָ���β 
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
