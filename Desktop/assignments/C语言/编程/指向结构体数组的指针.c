#include <stdio.h>
struct Student
{
	int num;
	char name[20];
	char sex;
	int age;
};
struct Student stu[2]={{10101,"li",'M',18},{10102,"zhang",'M',19}};
int main()
{
	struct Student *p;
	printf("NO.        Name            sex  age\n");
	for(p=stu;p<stu+2;p++)
	printf("%d%10s%14c%5d\n",p->num,p->name,p->sex,p->age);
	return 0;
}
