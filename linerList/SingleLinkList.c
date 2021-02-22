//
// Created by lmy on 2021-02-21.
//
#include "LinerList.h"

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;//此处声明struct LNode又叫 LNode（强调为节点） 或 *LinkList（强调为指向链表的指针）

//初始化空单链表(不带头节点)
bool snl_InitList(LinkList L)
{
    L = NULL;
    return true;
}

//初始化空单链表（带头节点)
bool sl_InitList(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if (L==NULL)
        return false;
    L->next = NULL;
    return true;
}

//判空
bool Empty(LinkList *L)
{
    if(L==NULL)
        return true;
    else
        return false;
}

//单链表主调用函数
int sl_main()
{
    return 3;
}
