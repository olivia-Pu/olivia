void Insert(Pointer * Head)   //插入函数的定义 
{
	int in_number;
	Pointer p,q,r;     //声明变量 
	printf("请输入编号：");
	scanf("%d",&in_number);
	p=q=*Head;  //寻找符合条件的记录 
	while(p!=NULL)
	{
		if(p->number==in_number)
		{
			printf("此编号已存在！"); return;  
		}
			else{ q=p;p=p->next;} // 依次访问 
	}
		r=malloc(sizeof(GuestLink));  // 申请储存空间 
		r->next=NULL;  //设置指针域 
		if(r==NULL)
		{
			printf("分配空间失败！"); return;
		}
		if(q==NULL)   // 空表 
		*Head=r;   //表头指向新结点 
		else {q->next=r;}  //从表尾插入新元素 
		r->number=in_number;  //接收数据 
		printf("\n         *************************************\n\n");
		printf("             请输入姓名:");
		scanf("%s",r->name);
		printf("             请输入人数:");
		scanf("%d",&r->sum);
		printf("             请输入用餐时间:");
		scanf("%s",r->time); 
		printf("             请输入电话号码:");
		scanf("%s",r->tel); 
		printf("             请输入菜品:");
		scanf("%s",r->food); 
		printf("             请输入包房与否:");
		scanf("%d",&r->serv); 
		printf("\n         *************************************\n\n");
}

void Search(Pointer  Head)   // 查找函数定义 
{
	int flag=1;  //标记变量 
	int number;
	Pointer p;
	printf("请输入需要查找的编号:");
	scanf("%d",&number);
	p=Head;    //寻找符合条件的记录 
	while(p!=NULL&&flag)
	{
		if(p->number==number)
		{
			printf("\n         *************************************\n\n");
	        printf("             姓名:%s\n",p->name);
		    printf("             人数:%d\n",p->sum);
	        printf("             用餐时间:%s\n",p->time);
	        printf("             电话号码:%s\n",p->tel); 
	        printf("             菜品:%s\n",p->food); 
	        printf("             包房与否(1/0):%d\n",p->serv);
	        flag=0;  //标记变量 
	        printf("\n         *************************************\n\n");
		}
		else p=p->next;   //指针依次后移 
	}
	if(flag)
	printf("该编号不存在!!\n");
}

void Update(Pointer  Head)  //修改函数定义 
{
	int flag=1;  //标记变量 
	int number;
	Pointer p;
	printf("请输入需要修改的编号:");
	scanf("%d",&number);
	p=Head;  //寻找符合条件的记录 
	while(p!=NULL&&flag)
	{
		if(p->number==number) 
		 {
		 	printf("\n         *************************************\n\n");
		     printf("             请输入人数:");
		     scanf("%d",&p->sum);
	         printf("             请输入用餐时间:");
		     scanf("%s",p->time);
		     printf("             请输入电话号码:");
		     scanf("%s",p->tel); 
		     printf("             请输入菜品:");
		     scanf("%s",p->food); 
		     printf("             请输入包房与否(1/0):");
		     scanf("%d",&p->serv); 
		     flag=0;  //标记变量 
		    printf("\n         *************************************\n\n");
		 }
		 else p=p->next;  //指针依次后移 
	}
	if(flag)
	printf("该编号不存在!!\n");
}

void Delete(Pointer * Head)  //删除函数定义 
{
	 int flag=1;
	 int number;
	 Pointer p,q;  //变量说明 
	 printf("请输入需要删除的编号：");
	 scanf("%d",&number);
	 p=q=*Head;   //寻找符合条件的记录 
   	 while(p!=NULL&&flag)
     {
     	if(p->number==number)
     	{
     		if(p==*Head)    //删除表头元素 
     		{
			     *Head=p->next;
			     free(p);
			}
			 else
			{
			     q->next=p->next;   //删除其他元素
				 free(p);
			}    
			 flag=0;
		 }
		 else
		 {q=p;p=p->next;}  //指针后移，q结点为p结点的前驱 
	 }
	 if(flag)
	 printf("该编号不存在!!\n");
}


void Show(Pointer  Head)   //显示函数的定义 
{
	printf("            ============================预订名单===============================     \n\n");
	Pointer p;
	int i=0;   //计数变量 
	p=Head;
	while(p!=NULL)
	{   
	    printf("姓名:%-10s",p->name);
		printf("人数:%-5d",p->sum);
	    printf("用餐时间:%-8s",p->time);
	    printf("电话:%-15s",p->tel);
	    printf("包房与否(1/0):%-5d",p->serv);
	    printf("编号:%-4d\n",p->number);
	    printf("菜品:","%s\n",p->food);
	    printf("\n");
	    p=p->next;++i;
	}
	printf("\n客户订单人数:%d\n",i);
	printf("\n            ===================================================================      ");
}
