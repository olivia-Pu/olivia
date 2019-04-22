#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <Mmsystem.h>
#pragma comment ( lib, "Winmm.lib" )
/***** 宏定义区 ******/
#define NUM13// 烟花种类数量宏定义
#define PI 3.1415926548
/***** 结构定义区 **********/
// 烟花结构
struct FIRE
{
int r;// 当前爆炸半径
int max_r;// 爆炸中心距离边缘最大半径
int x, y;// 爆炸中心在窗口的坐标
int cen_x, cen_y;// 爆炸中心相对图片左上角的坐标
int width, height;// 图片的宽高
int xy[240][240];// 储存图片像素点
bool show;// 是否绽放
bool draw;// 开始输出像素点
DWORD t1, t2, dt;// 绽放速度
}Fire[NUM];
// 烟花弹结构
struct JET
{
int x, y;// 喷射点坐标
int hx, hy;// 最高点坐标------将赋值给 FIRE 里面的 x, y
int height;// 烟花高度
bool shoot;// 是否可以发射
DWORD t1, t2, dt;// 发射速度
IMAGE img[2];// 储存花弹一亮一暗图片
byte n : 1;// 图片下标
}Jet[NUM];
/**** 函数申明区 ****/
void welcome();
void Init(int);// 初始化烟花
void Load();// 加载烟花图片
void Shoot();// 发射烟花
void Chose(DWORD&);// 筛选烟花
void Style(DWORD&);// 发射样式
void Show(DWORD*);// 绽放烟花
// 主函数
void main()
{
initgraph(1200, 800);
srand(time(0));
// 播放背景音乐
mciSendString("open ./fire/小幸运.mp3 alias bk", 0, 0, 0);
mciSendString("play bk repeat", 0, 0, 0);
welcome();
DWORD t1 = timeGetTime();// 筛选烟花计时
DWORD st1 = timeGetTime();// 播放花样计时
DWORD* pMem = GetImageBuffer();// 获取窗口显存指针
for (int i = 0; i < NUM; i++)// 初始化烟花
{
Init(i);
}
Load();// 将烟花图片信息加载进相应结构中
BeginBatchDraw();// 开始批量绘图
while (!kbhit())
{
Sleep(10);
// 随机选择 4000 个像素点擦除
for (int clr = 0; clr < 1000; clr++)
{
for (int j = 0; j < 2; j++)
{
int px1 = rand() % 1200;
int py1 = rand() % 800;
if (py1 < 799)// 防止越界
pMem[py1 * 1200 + px1] = pMem[py1 * 1200 + px1 + 1] = BLACK;// 对显存赋值擦出像素点
}
}
Chose(t1);// 筛选烟花
Shoot();// 发射烟花
Show(pMem);// 绽放烟花
Style(st1);// 花样发射
FlushBatchDraw();// 显示前面的所有绘图操作
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
settextstyle(i, 0, "楷体");
outtextxy(x, y, "双十一,不剁手!");
outtextxy(x-130, y+100, "写段代码送女友！");
Sleep(25);
}
getchar();
cleardevice();
settextstyle(25, 0, "楷体");
outtextxy(400, 200, "原来你是我最想留住的幸运");
outtextxy(400, 250, "原来我们和爱情曾经靠得那么近");
outtextxy(400, 300, "那为我对抗世界的决定");
outtextxy(400, 350, "那陪我淋的雨");
outtextxy(400, 400, "一幕幕都是你");
outtextxy(400, 450, "一尘不染的真心。");
outtextxy(600, 500, "----《小幸运》");
