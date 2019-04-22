#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define m 100
typedef struct
 {
  char stack[m];
  int  top;
}stackstru;  // ����ջ
 
typedef struct {
 char queue[m];
 int  front;
 int  rear;
}queuestru; //�������
 
int main()
{
  //��������
  int stinit(stackstru *s);         //��ʼ��˳��ջ
  int stempty(stackstru *s);        //�ж�ջ�Ƿ�Ϊ��
  int stpush(stackstru *s,char x);  //��ջ
  char stpop(stackstru *s);         //��ջ
  int quinit(queuestru *q);         //��ʼ��ѭ������
  int quempty(queuestru *q);        //�ж϶����Ƿ�Ϊ��
  int enqueue(queuestru *q,char e); //���
  char dequeue(queuestru *q);       //����                                 
  char c;
  int flag=0;
  stackstru *s=(stackstru *)malloc(sizeof(stackstru)); //Ϊ˳��ջ����ռ�
  queuestru *q=(queuestru *)malloc(sizeof(queuestru)); //Ϊ��������ռ�
  stinit(s);   //��ʼ��ջ
  quinit(q);   //��ʼ������
  printf("Input a string:\n");//�����ַ���������@��ʾ���������
  while((c=getchar())!='@')   //��������ַ�����ջ�Ͷ���
  { 
    if(c!=' ')
    {
     c=tolower(c);   
     stpush(s,c);              //�ַ���ջ
     enqueue(q,c);             //�ַ�������
    }
  }
  while(stempty(s))           //ջ�л���Ԫ��
   {
     if(stpop(s)==dequeue(q)) //��ջ���ַ�������е��ַ�ƥ��
     {
      flag=1;                 //����־����Ϊ1  
      continue;               //������ջ�Ͷ��������ַ�
     }
     else                     //�ַ���ƥ��
     {
      flag=0;
      break;                  //����ѭ��������־����Ϊ0
     }
   }
  if(flag==1)
    printf("���ַ����ǻ��ģ�\n"); //��־λΪ1����ȫƥ�䣬�ǻ���
   
  else
    printf("���ַ������ǻ��ģ�\n");//��־λΪ0������ȫƥ�䣬���ǻ���
  return 0;
}
 
int stinit(stackstru *s)
{
  s->top=0;
  return 1;
}           //��ʼ��ջ
 
int stempty(stackstru *s)
{
  if(s->top==0)                         //ջ��Ϊ��
  {
    return 0;
  }
  else
  {
    return 1;
  }
}           //�ж�ջ�Ƿ��
 
int stpush(stackstru *s,char x)
{
  if(s->top==m)                          //ջ��
   {
     printf("The stack is overflow!\n"); //�����ʾ��Ϣ
     return 0;
  }                        
  else                                   //ջδ��
   {
     s->top=s->top+1;                    //ջ������
     s->stack[s->top]=x;                 //�ַ���ջ
     return 1;
   }
}          //��ջ����
 
char stpop(stackstru *s)
{
  char y;
  if(s->top==0)                          //ջΪ��
  {
    printf("The stack is empty!\n");     //�����ʾ��Ϣ
    return ' ';                          //���ؿո�
  }
  else                                   //ջ��Ϊ��
  {    
    y=s->stack[s->top];                  //ȡ��ջ��Ԫ��
    s->top=s->top-1;                     //ջ��ָʾ�ƶ�
    return y;
  }
}         //��ջ����
 
int quinit(queuestru *q)
{
  q->front=0;                           
  q->rear=0;
  return 1;
}          //��ʼ��Ϊһ���յ�ѭ������
 
int quempty(queuestru *q)
{
  if(q->front==q->rear)                 //��ͷ�Ͷ�β���
  {
   return 0;
  }
  else
  {
   return 1;
  }
}          //�ж϶����Ƿ�Ϊ��
 
int enqueue(queuestru *q,char e)
{
  if((q->rear+1)%m==q->front)           //��������
   {
    printf("The queue is overflow!\n"); //��ʾ��Ϣ
    return 0;
   }
   else
   {
    q->queue[q->rear]=e;                //���
    q->rear=(q->rear+1)%m;              //�ƶ���βָ��
    return 1;
   }
}         //��Ӳ���
 
char dequeue(queuestru *q)
{
  char f;
  if(q->front==q->rear)                  //����Ϊ��
   {
     printf("The queue is empty!\n");    //��ʾ��Ϣ
     return 0;
   }
   else
   {
     f=q->queue[q->front];               //ȡ������Ԫ��
     q->front=(q->front+1)%m;            //�ƶ���ͷָ��
     return f;
   }
}        //���Ӳ���
