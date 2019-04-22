#include <stdio.h>
#define N 5
 struct student
{
	int num;
	char name[20];
	int score;
}*p,stu[N];

int main()
{
	void input(struct student stu[]);
	struct student max(struct student stu[]);
	void print(struct student stu);
    p=stu; 
	input(p);
	print(max(p));
	return 0;
}

void input(struct student stu[])
{
	int i;
	printf("请输入5名学生的信息：学号.姓名.成绩\n");
	for(i=0;i<N;i++)
	{
		scanf("%d%s%d",&stu[i].num,stu[i].name,&stu[i].score);
	}
}

struct student max(struct student stu[])
{
	int i,m=0;
	for(i=0;i<N;i++)
	if(stu[i].score>stu[m].score)
	m=i;
	return stu[m];
}

void print(struct student stud)
{
	printf("\n成绩最高的学生是:\n");
	printf("学号：%d   姓名：%s   成绩：%d",stud.num,stud.name,stud.score);
}
