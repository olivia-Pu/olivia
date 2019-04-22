#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
struct student
{
	char name[10];
	int num;
	int score[3];
	float ave;
}stu[SIZE],work;

int main()
{
	void sort();
	int i;
	FILE *fp;
	 sort();
	 fp=fopen("stu_sort.dat","rb");
	 printf("sorted student's scores list as follows\n"); 
	 printf("---------------------------------------------------------");
	 printf("\nname      NO:      score1    score2    score3    ave \n");
	 printf("---------------------------------------------------------\n");
	 
	 for(i=0;i<SIZE;i++)
	 {
	 	fread(&stu[i],sizeof(struct student),1,fp);
	 	printf("%-10s%3d%10d%10d%10d%10.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
	 }
	 fclose(fp);
	 return 0;
}
void sort()
{
	FILE *fp1,*fp2;
	int i,j;
	if((fp1=fopen("stu.dat","rb"))==NULL)
	{
		printf("The file can not open\n\n");
		return ;
	}
	if((fp2=fopen("stu_sort.dat","wb"))==NULL)
	{
		printf("file write error\n");
		return;
	}
	for(i=0;i<SIZE;i++)
	if(fread(&stu[i],sizeof(struct student),1,fp1)!=1)
	{
		printf("file read error\n");
		return;
	}
	for(i=0;i<SIZE;i++)
	{
		for(j=i+1;j<SIZE;j++)
		  if(stu[i].ave<stu[j].ave)
		  {
		  	work=stu[i];
		  	stu[i]=stu[j];
		  	stu[j]=work;
		  }
		  fwrite(&stu[i],sizeof(struct student),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
