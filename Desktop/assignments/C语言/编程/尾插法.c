#include "stdio.h"
#include "stdlib.h"
typedef struct List {
int data; //������
struct List *next; //ָ����
} List;

void TailCreatList(List *L) //β�巨��������
{
List *s, *r;//s����ָ�������ɵĽڵ㡣rʼ��ָ��L���ն˽ڵ㡣
r = L; //rָ����ͷ�ڵ㣬��ʱ��ͷ�ڵ����ն˽ڵ㡣
int i ;
for (i = 0; i < 10; i++) {
s = (struct List*) malloc(sizeof(struct List));//sָ��������Ľڵ�
s->data = i; //���½ڵ��������������i
r->next = s; //��r�������½ڵ�
r = s; //rָ���ն˽ڵ�
}
r->next = NULL; //Ԫ���Ѿ�ȫ��װ������L��
//L���ն˽ڵ�ָ����ΪNULL��L�������

}
void DisPlay(List *L) { //��ӡ�ڵ�
List *p = L->next;
while (p != NULL) {
printf("%d ", p->data);
p = p->next;
}
printf("\n");
}
int main() {
List *L1, *L2;
L1 = (struct List*) malloc(sizeof(struct List));
L2 = (struct List*) malloc(sizeof(struct List));
HeadCreatList(L1);
DisPlay(L1);
TailCreatList(L2);
DisPlay(L2);
}
