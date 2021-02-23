//
// Created by lmy on 2021-02-21.
//
#include "LinerList.h"

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;//此处声明struct LNode又叫 LNode（强调为节点） 或 *LinkList（强调为指向链表的指针）

/*
 * 不带头节点单链表
 */
//初始化空单链表(不带头节点)
LinkList nsl_InitList(LinkList L)
{
    L = NULL;
    return L;
}

//判空（不带头节点）
bool nsl_Empty(LinkList L)
{
    if(L==NULL)
        return true;
    else
        return false;
}

//主调用函数（不带头结点）
int nsl_main()
{
    LinkList L;//指向链表的指针
    L = nsl_InitList(L);
    if(nsl_Empty(L))
    {
        printf("不带头节点单链表为空\n");
        fflush(stdout);
    } else
    {
        printf("不带头节点单链表非空\n");
        fflush(stdout);
    }
    return 3;
}


////////////////////////////////////////////////
/*
 * 带头节点单链表
 */
//初始化空单链表（带头节点)
LinkList sl_InitList(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if (L==NULL)
        return false;
    L->next = NULL;
    return L;
}

//判空（带头节点）
bool sl_Empty(LinkList L) {
    if (L->next == NULL)
        return true;
    return false;
}

//主调用函数（带头结点）
int sl_main()
{
    LinkList L;
    L = sl_InitList(L);
    if(sl_Empty(L))
    {
        printf("带头节点单链表为空\n");
        fflush(stdout);
    } else
    {
        printf("带头节点单链表非空\n");
        fflush(stdout);
    }
    return 4;
}