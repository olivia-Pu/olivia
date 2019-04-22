#include "stdio.h"
#include "stdlib.h"
typedef struct List {
int data; //数据域
struct List *next; //指针域
} List;

void TailCreatList(List *L) //尾插法建立链表
{
List *s, *r;//s用来指向新生成的节点。r始终指向L的终端节点。
r = L; //r指向了头节点，此时的头节点是终端节点。
int i ;
for (i = 0; i < 10; i++) {
s = (struct List*) malloc(sizeof(struct List));//s指向新申请的节点
s->data = i; //用新节点的数据域来接受i
r->next = s; //用r来接纳新节点
r = s; //r指向终端节点
}
r->next = NULL; //元素已经全部装入链表L中
//L的终端节点指针域为NULL，L建立完成

}
void DisPlay(List *L) { //打印节点
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
