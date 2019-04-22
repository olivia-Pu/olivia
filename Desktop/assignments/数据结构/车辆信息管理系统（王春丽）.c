#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define list_init_size 100  //分配100个车位容量 
#define listincrement 10
#define OK 1
#define ERROR 0

typedef struct car
{
	
	char tag[5];   //存放in ，in表示车位有车 
	char carnum[20];//车牌号 
	int num;      // 存放车位 
	char name[20];  //车主姓名 
	char tele[20];  //挪车电话 
	float date;     //停车日期 
}car;

typedef struct{
	car *elem;
	int length;//当前长度 
	int listsize;//当前分配的存储容量 
}sqlist;

int main()
{
    int InitList_Sq(sqlist *L); //初始化顺序表函数声明 
    void CreteList_Sq(sqlist *L); //车辆信息录入函数声明 
	void Listfind_Sq(sqlist *L,int a); //通过车位来查询有关车的信息函数声明 
    void Listfond_Sq(sqlist *L,char n[]);//按车主姓名查询有关车的信息函数声明
	void Listfind_L(sqlist *L,char m[]);//通过挪车电话来查询有关车的信息函数声明
	void Listout_L(sqlist *L); //显示当前车站所有车的信息函数声明 
	void Listfind_Ln(sqlist *L,int h);//查询某个车位是否有车函数声明
	int CurrentCarSpaces(sqlist *L); //定义“显示当前车位用量和余量”的函数
	void Today_Count(sqlist *L,float k);//查询某天进站车辆总数 
	void menu();//显示菜单函数声明 
	
	
    sqlist L1;
    int i,k,date,b,p,e;
    float t;
    p=0;
    char name[20];
	char tele[20];
    k=InitList_Sq(&L1);//调用InitList_Sq实现车辆信息表的初始化 
    if(k==ERROR)
    	{
		printf("车辆信息表初始化失败！");
    	return 0;//退出程序
    	}
    while(p==0) 
    {
       menu();
       printf("\n请选择功能：");
	   scanf("%d",&e);
	   
	   if(e==1)
		{
		 CreteList_Sq(&L1);//车辆信息录入 
		}
		
        if(e==2)
         {
           printf("\n按车主姓名查询有关车的信息"); //按车主姓名查询有关车的信息
           printf("\n请输入要查询的车主姓名：");
           scanf("%s",name);
           Listfond_Sq(&L1,name);
         }
         
        if(e==3)
         {
           printf("\n按挪车电话查询有关车的信息"); //通过挪车电话来查询有关车的信息
           printf("\n请输入挪车电话：");
           scanf("%s",tele);
           Listfind_L(&L1,tele);
         }
         
        if(e==4)
         {
           printf("\n显示当前站内所有车的信息！") ; //显示当前站内所有车的信息
           Listout_L(&L1) ;
         }  
        if(e==5) 
        {
	       printf("请输入车位号：");  //查询某个车位是否有车 
	       scanf("%d",&b) ;
	       Listfind_Ln(&L1,b);
    	} 
    	if(e==7)
    	{
    		CurrentCarSpaces(&L1);//显示当前车位用量和余量 
		}
		
		 if(e==6)
	    {
          printf("\n按车位查询有关车的信息"); //按车位查询有关车的信息
          printf("\n请输入要查询的车位号：");
          scanf("%d",&i);
          Listfind_Sq(&L1,i);
         }
		if(e==8)
		{ 
		    printf("请输入要查询的日期:");
	        scanf("%f",&t);
			Today_Count(&L1,t);//查询某天进站车辆总数
		 } 
		if(e==0) 
		  break;
    }
 return 0;
}

void menu() 
  {
  	printf("\n");
	printf("\n**************欢迎使用校园车辆信息管理系统**************\n");
    printf("\t*******请选择功能列表*******\n"); 
	printf("\t\t1.车辆信息录入\n");
	printf("\t\t2.按车主姓名查询有关车的信息\n");
	printf("\t\t3.通过挪车电话来查询有关车的信息\n");
	printf("\t\t4.显示当前站内所有车的信息\n");
	printf("\t\t5.查询某个车位是否有车\n");
	printf("\t\t6.按车位查询有关车的信息\n");
	printf("\t\t7.查询当前车位用量和余量\n");
	printf("\t\t8.显示某天进站的车辆总数\n");
	printf("\t\t0.退出系统\n");
 }
 
int InitList_Sq(sqlist *L)  //顺序表初始化 
{
	L->elem=(car *)malloc(sizeof(car)*list_init_size);
	if(L->elem==NULL)
	   return ERROR;
	L->length=0;
	L->listsize=list_init_size;
	return OK; 
}

void CreteList_Sq(sqlist *L)  //车辆信息录入
 {
    int i,e;
    i=0;
    e=0;
    for(;i<=L->listsize-1,e==0;i++)
 	   {   
 		 
		printf("\n请输入车辆的：标志 车牌号 车位 车主姓名 挪车电话 日期 ：");
		scanf("%s %s %d %s %s %f",L->elem[i].tag,L->elem[i].carnum,&L->elem[i].num,L->elem[i].name,L->elem[i].tele,&L->elem[i].date);
		L->length=L->length+1;
		printf("是否完成信息录入？1/0：");//输 0就继续录入，输 1就结束录入 
		scanf("%d",&e);	 
	   }
 }
 
void Listfond_Sq(sqlist *L,char n[]) //按车主姓名查询有关车的信息函数
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
			  printf("输入车主姓名错误！"); 
		}
}

void Listfind_Sq(sqlist *L,int a) //通过车位来查询信息函数
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
	   printf("车位没有车！"); 
}

void Listfind_L(sqlist *L,char m[]) //通过挪车电话来查询有关车的信息函数声明
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
			  printf("输入挪车电话错误！"); 
		}
} 
	
void Listout_L(sqlist *L)  //显示当前车站所有车的信息函数
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

void Listfind_Ln(sqlist *L,int h) //查询某个车位是否有车函数
{
	char m[5]={"in"};
	if(strcmp(L->elem[h].tag,m)==0)
	  printf("有车！"); 
	else
	  printf("无车！"); 
}

int CurrentCarSpaces(sqlist *L) //定义一个“显示当前车位用量和余量”的函数 
{
	int Find_IN(sqlist *L);  //声明 
	int IN;  //IN用于存放当前车位用量
	int OUT; //OUT用于存放当前车位剩余量 
	
	IN=Find_IN(L);  // IN 的值即为count1返回给 Find_IN(sqlist *L)的值 
	OUT=L->listsize-IN; 
	
	printf("当前车位用量：%d\n",IN);
	printf("当前车位余量：%d\n",OUT);

}

int Find_IN(sqlist *L)  //自定义IN计数函数，在 L中查找字符 in，并返回其出现个数 
{
	char o[]="in"; //定义数组存放字符‘in’ 
	int i;
	int count1=0;

	for(i=0;i<=L->length-1;i++)
	{
      if(strcmp(L->elem[i].tag,o)==0) //比较函数 if(strcmp(string1, string2) == 0)
	  count1++;
    }
 	return count1;  //count1的值返回给 Find_IN(sqlist *L)
}


void Today_Count(sqlist *L,float k)//查询某天进站车辆总数 
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
