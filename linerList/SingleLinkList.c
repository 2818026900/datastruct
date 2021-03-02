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

//头插法创建单链表（带头节点）
LinkList sl_createByHeadInsert(LinkList L)
{
    ElemType x;//定义元素类型
    LNode* node;//定义新节点
    printf("头插法：请输入想插入数据，输入-1结束\n");
    fflush(stdout);
    while (1)
    {
        scanf("%d",&x);
        if(x == -1)
            return L;
        node = (LNode*) malloc(sizeof(x));
        node->data = x;
        node->next = L->next;
        L->next = node;
    }
}

//尾插法创建单链表（带头节点）
LinkList sl_createByTailInsert(LinkList L)
{
    ElemType x;
    LNode *node, *tail;
    printf("尾插法：请输入想插入数据，输入-1结束\n");
    fflush(stdout);
    tail = L;
    while (1)
    {
        scanf("%d",&x);
        if(x == -1)
        {
            tail->next = NULL;//一定要加入这一步使得数据指向空不然会出现无限循环现象
            return L;
        }
        node = (LNode*)malloc(sizeof(ElemType));
        node->data = x;
        tail->next = node;
        tail = node;
    }
}

//打印单链表（带头节点）
void sl_printLink(LNode* node)
{
    node = node->next;//指向头节点之后
    printf("头插法创建的单链表数据为：\n");
    while (node != NULL)
    {
        printf("%d\t",node->data);
        node = node->next;
    }
    printf("\n");
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
    L = sl_createByHeadInsert(L);
    sl_printLink(L);
    printf("\n");
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
    L = sl_createByTailInsert(L);
    sl_printLink(L);
    return 4;
}