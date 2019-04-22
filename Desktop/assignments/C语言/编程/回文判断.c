#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define m 100
typedef struct
 {
  char stack[m];
  int  top;
}stackstru;  // 定义栈
 
typedef struct {
 char queue[m];
 int  front;
 int  rear;
}queuestru; //定义队列
 
int main()
{
  //函数声明
  int stinit(stackstru *s);         //初始化顺序栈
  int stempty(stackstru *s);        //判断栈是否为空
  int stpush(stackstru *s,char x);  //入栈
  char stpop(stackstru *s);         //出栈
  int quinit(queuestru *q);         //初始化循环队列
  int quempty(queuestru *q);        //判断队列是否为空
  int enqueue(queuestru *q,char e); //入队
  char dequeue(queuestru *q);       //出队                                 
  char c;
  int flag=0;
  stackstru *s=(stackstru *)malloc(sizeof(stackstru)); //为顺序栈申请空间
  queuestru *q=(queuestru *)malloc(sizeof(queuestru)); //为队列申请空间
  stinit(s);   //初始化栈
  quinit(q);   //初始化队列
  printf("Input a string:\n");//输入字符串，输入@标示输入结束。
  while((c=getchar())!='@')   //将输入的字符串入栈和队列
  { 
    if(c!=' ')
    {
     c=tolower(c);   
     stpush(s,c);              //字符进栈
     enqueue(q,c);             //字符进队列
    }
  }
  while(stempty(s))           //栈中还有元素
   {
     if(stpop(s)==dequeue(q)) //出栈的字符与出队列的字符匹配
     {
      flag=1;                 //将标志设置为1  
      continue;               //继续从栈和队列中区字符
     }
     else                     //字符不匹配
     {
      flag=0;
      break;                  //跳出循环，将标志设置为0
     }
   }
  if(flag==1)
    printf("该字符串是回文！\n"); //标志位为1，完全匹配，是回文
   
  else
    printf("该字符串不是回文！\n");//标志位为0，不完全匹配，不是回文
  return 0;
}
 
int stinit(stackstru *s)
{
  s->top=0;
  return 1;
}           //初始化栈
 
int stempty(stackstru *s)
{
  if(s->top==0)                         //栈顶为空
  {
    return 0;
  }
  else
  {
    return 1;
  }
}           //判断栈是否空
 
int stpush(stackstru *s,char x)
{
  if(s->top==m)                          //栈满
   {
     printf("The stack is overflow!\n"); //输出提示信息
     return 0;
  }                        
  else                                   //栈未满
   {
     s->top=s->top+1;                    //栈顶后移
     s->stack[s->top]=x;                 //字符入栈
     return 1;
   }
}          //入栈操作
 
char stpop(stackstru *s)
{
  char y;
  if(s->top==0)                          //栈为空
  {
    printf("The stack is empty!\n");     //输出提示信息
    return ' ';                          //返回空格
  }
  else                                   //栈不为空
  {    
    y=s->stack[s->top];                  //取出栈顶元素
    s->top=s->top-1;                     //栈顶指示移动
    return y;
  }
}         //出栈操作
 
int quinit(queuestru *q)
{
  q->front=0;                           
  q->rear=0;
  return 1;
}          //初始化为一个空的循环队列
 
int quempty(queuestru *q)
{
  if(q->front==q->rear)                 //队头和队尾相等
  {
   return 0;
  }
  else
  {
   return 1;
  }
}          //判断队列是否为空
 
int enqueue(queuestru *q,char e)
{
  if((q->rear+1)%m==q->front)           //队列已满
   {
    printf("The queue is overflow!\n"); //提示信息
    return 0;
   }
   else
   {
    q->queue[q->rear]=e;                //入队
    q->rear=(q->rear+1)%m;              //移动队尾指针
    return 1;
   }
}         //入队操作
 
char dequeue(queuestru *q)
{
  char f;
  if(q->front==q->rear)                  //队列为空
   {
     printf("The queue is empty!\n");    //提示信息
     return 0;
   }
   else
   {
     f=q->queue[q->front];               //取出队首元素
     q->front=(q->front+1)%m;            //移动对头指针
     return f;
   }
}        //出队操作
