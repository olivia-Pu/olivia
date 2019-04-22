#include <stdio.h>
#define SIZE 3
struct student
{
	char name[10];
	int num;
	int score[3];
	float ave;
}stu[SIZE];

int main()
{
	void save();
	int i;
	float sum[SIZE];
	FILE *fp1;
	for(i=0;i<SIZE;i++)
	{
		scanf("%s%d%d%d%d",stu[i].name,&stu[i].num,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		sum[i]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
		stu[i].ave=sum[i]/3.0;
	 } 
	 save();
	 fp1=fopen("stu.dat","rb");
	 printf("---------------------------------------------------------");
	 printf("\nname      NO:      score1    score2    score3    ave \n");
	 printf("---------------------------------------------------------\n");
	 
	 for(i=0;i<SIZE;i++)
	 {
	 	fread(&stu[i],sizeof(struct student),1,fp1);
	 	printf("%-10s%3d%10d%10d%10d%10.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
	 }
	 fclose(fp1);
	 return 0;
}
void save()
{
	FILE *fp;
	int i;
	if((fp=fopen("stu.dat","wb"))==NULL)
	{
		printf("The file can not open\n");
		return;
	}
	for(i=0;i<SIZE;i++)
	if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
	{
		printf("file write error\n");
		return; 
	}
	fclose(fp);
}
