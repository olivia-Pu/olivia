#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <Mmsystem.h>
#pragma comment ( lib, "Winmm.lib" )
/***** �궨���� ******/
#define NUM13// �̻����������궨��
#define PI 3.1415926548
/***** �ṹ������ **********/
// �̻��ṹ
struct FIRE
{
int r;// ��ǰ��ը�뾶
int max_r;// ��ը���ľ����Ե���뾶
int x, y;// ��ը�����ڴ��ڵ�����
int cen_x, cen_y;// ��ը�������ͼƬ���Ͻǵ�����
int width, height;// ͼƬ�Ŀ��
int xy[240][240];// ����ͼƬ���ص�
bool show;// �Ƿ�����
bool draw;// ��ʼ������ص�
DWORD t1, t2, dt;// �����ٶ�
}Fire[NUM];
// �̻����ṹ
struct JET
{
int x, y;// ���������
int hx, hy;// ��ߵ�����------����ֵ�� FIRE ����� x, y
int height;// �̻��߶�
bool shoot;// �Ƿ���Է���
DWORD t1, t2, dt;// �����ٶ�
IMAGE img[2];// ���滨��һ��һ��ͼƬ
byte n : 1;// ͼƬ�±�
}Jet[NUM];
/**** ���������� ****/
void welcome();
void Init(int);// ��ʼ���̻�
void Load();// �����̻�ͼƬ
void Shoot();// �����̻�
void Chose(DWORD&);// ɸѡ�̻�
void Style(DWORD&);// ������ʽ
void Show(DWORD*);// �����̻�
// ������
void main()
{
initgraph(1200, 800);
srand(time(0));
// ���ű�������
mciSendString("open ./fire/С����.mp3 alias bk", 0, 0, 0);
mciSendString("play bk repeat", 0, 0, 0);
welcome();
DWORD t1 = timeGetTime();// ɸѡ�̻���ʱ
DWORD st1 = timeGetTime();// ���Ż�����ʱ
DWORD* pMem = GetImageBuffer();// ��ȡ�����Դ�ָ��
for (int i = 0; i < NUM; i++)// ��ʼ���̻�
{
Init(i);
}
Load();// ���̻�ͼƬ��Ϣ���ؽ���Ӧ�ṹ��
BeginBatchDraw();// ��ʼ������ͼ
while (!kbhit())
{
Sleep(10);
// ���ѡ�� 4000 �����ص����
for (int clr = 0; clr < 1000; clr++)
{
for (int j = 0; j < 2; j++)
{
int px1 = rand() % 1200;
int py1 = rand() % 800;
if (py1 < 799)// ��ֹԽ��
pMem[py1 * 1200 + px1] = pMem[py1 * 1200 + px1 + 1] = BLACK;// ���Դ渳ֵ�������ص�
}
}
Chose(t1);// ɸѡ�̻�
Shoot();// �����̻�
Show(pMem);// �����̻�
Style(st1);// ��������
FlushBatchDraw();// ��ʾǰ������л�ͼ����
}
}
void welcome()
{
//setfillstyle(0);
setcolor(YELLOW);
for (int i = 0; i < 50; i++)
{
int x = 600 + int(180 * sin(PI * 2 * i / 60));
int y = 200 + int(180 * cos(PI * 2 * i / 60));
cleardevice();
settextstyle(i, 0, "����");
outtextxy(x, y, "˫ʮһ,������!");
outtextxy(x-130, y+100, "д�δ�����Ů�ѣ�");
Sleep(25);
}
getchar();
cleardevice();
settextstyle(25, 0, "����");
outtextxy(400, 200, "ԭ��������������ס������");
outtextxy(400, 250, "ԭ�����ǺͰ�������������ô��");
outtextxy(400, 300, "��Ϊ�ҶԿ�����ľ���");
outtextxy(400, 350, "�������ܵ���");
outtextxy(400, 400, "һĻĻ������");
outtextxy(400, 450, "һ����Ⱦ�����ġ�");
outtextxy(600, 500, "----��С���ˡ�");
