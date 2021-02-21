//
// Created by lmy on 2021-02-19.
//静态顺序表返回值为1，动态顺序表返回值为2
//
#include "LinerList.h"

#define ElemType int //定义元素类型

///////////////////////////////////////////////////
/*
 * 静态顺序表SeqList
 */
#define MaxSize 100 //定义最大长度

typedef struct {
    ElemType data[MaxSize];
    int size;
} SeqList; //定义静态顺序表数据结构

//初始化静态顺序表
void seq_initList(SeqList* SeqL)
{
    for(int i=0; i<MaxSize; i++)
    {
        SeqL->data[i] = 0;//初始化所有元素为0
    }
    SeqL->size = 0;
}

//插入指定元素在指定位置
void seq_listInsert(SeqList* SeqL, int i, ElemType e)
{
    if(i<1||i>SeqL->size+1)
    {
        printf("您输入的位置有问题\n");
        return;
    }
    if(SeqL->size>=MaxSize)
    {
        printf("当前顺序表已满,不能再次插入\n");
        return;
    }
    for(int j=SeqL->size; j>=i; j--)//后移i位置及之后元素
    {
        SeqL->data[j] = SeqL->data[j-1];
    }
    SeqL->data[i-1] = e;//在i处赋值e
    SeqL->size++;
}

//删除指定位置元素元素并获取改元素值
int seq_listDelete(SeqList* SeqL, int i, ElemType* e)
{
    if(i<1||i>SeqL->size)
    {
        printf("您所要删除元素的位置有误\n");
        return -1;
    }
    *e = SeqL->data[i-1];
    for(int j=i; j<SeqL->size; j++)
    {
        SeqL->data[j-1] = SeqL->data[j];
    }
    SeqL->size--;
    return 0;
}

//按位查找静态顺序表
ElemType seq_getElem(SeqList SeqL, int i)
{
    if(i<0||i>SeqL.size)
    {
        printf("您所查找的位置有误\n");
        return -1;
    }
    return SeqL.data[i-1];
}

//按值查找静态顺序表
ElemType seq_locateElem(SeqList SeqL, ElemType e)
{
    for(int i=0; i<SeqL.size; i++)
    {
        if(SeqL.data[i]==e)
            return i+1;
    }
    printf("您所查找的值不存在\n");
    return 0;
}

//遍历静态顺序表
void seq_printList(SeqList SeqL)
{
    for(int i=0; i<SeqL.size; i++)
    {
        if(i%5!=4)//5个数一行
        {
            printf("第%d个数 %d\t", i+1, SeqL.data[i]);
        }
        else
        {
            printf("第%d个数 %d\n", i+1, SeqL.data[i]);
            fflush(stdout);
        }
    }
    printf("\n");
    fflush(stdout);
}

//静态顺序表主调用函数
int seq_main()
{
    SeqList SeqL;//声明静态顺序表

    seq_initList(&SeqL);

    printf("\n插入元素\n");
    for(int i=0; i<10; i++){
        seq_listInsert(&SeqL, i+1, i+1);
    }
    printf("插入数据前\n");
    fflush(stdout);
    seq_printList(SeqL);
    int i;
    ElemType e;
    printf("请输入所插元素位置：\n");
    fflush(stdout);
    scanf("%d",&i);
    printf("请输入所要插入的元素：\n");
    fflush(stdout);
    scanf("%d",&e);
    seq_listInsert(&SeqL, i, e);
    printf("插入数据后\n");
    fflush(stdout);
    seq_printList(SeqL);


    printf("\n删除元素\n");
    printf("请输入所要删除元素的位置:\n");
    fflush(stdout);
    scanf("%d",&i);
    if(seq_listDelete(&SeqL, i, &e)==0)
    {
        printf("已删除元素e= %d\n",e);
        fflush(stdout);
    }
    else
    {
        printf("删除失败\n");
        fflush(stdout);
    }
    seq_printList(SeqL);

    printf("\n查找元素\n");
    printf("按位查找\n");
    printf("请输入所要查找元素的位置：\n");
    fflush(stdout);
    scanf("%d",&i);
    e = seq_getElem(SeqL, i);
    if(e!=-1)
        printf("位于%d位置的元素为 %d\n", i, e);
    printf("\n");
    printf("按值查找\n");
    printf("请输入所要查找的元素：\n");
    fflush(stdout);
    scanf("%d",&e);
    i = seq_locateElem(SeqL, e);
    if(i != 0)
        printf("您所查找的元素%d位于 %d\n", e, i);
    fflush(stdout);
    return 1;
}


//////////////////////////////////////////////////////////////
/*
 * 动态顺序表SqList
 */
#define InitSize 10 //初始长度

typedef struct {
    ElemType *base;
    int MaxLength;
    int length;
} SqList;

//初始化动态顺序表
void sq_initList(SqList* SqL)
{
    SqL->MaxLength = InitSize;
    SqL->base = (ElemType*)malloc(sizeof(ElemType)*SqL->MaxLength);
    SqL->length = 0;
}

//动态增加顺序表长度,一般分配两倍
SqList sq_increaseLength(SqList* SqL)
{
    ElemType* NewBase;//新的基地址
    NewBase = (ElemType*)realloc(SqL->base, sizeof(ElemType*)*SqL->MaxLength*2);
    SqL->base = NewBase;
    SqL->MaxLength = SqL->MaxLength*2;
    return *SqL;
}

//插入指定元素在指定位置
void sq_listInsert(SqList* SqL, int i, ElemType e)
{
    if(SqL->length == SqL->MaxLength)
    {
        printf("空间不足，重新分配\n");
        fflush(stdout);
        sq_increaseLength(SqL);
    }
    if(i<1||i>SqL->length+1)
    {
        printf("您输入的位置有误\n");
        fflush(stdout);
        return;
    }
    for(int j=SqL->length; j>i-1; j--)
    {
        *(SqL->base+j) = *(SqL->base+j-1);//另外写法参考静态顺序表
    }
    *(SqL->base+i-1) = e;
    SqL->length++;
}

//删除指定位置元素元素并获取改元素值
int sq_listDelete(SqList* SqL, int i, ElemType* e)
{
    if(i<0||i>SqL->length)
    {
        printf("您所要删除元素的位置有误\n");
        return -1;
    }
    *e = *(SqL->base+i-1);
    for(int j=i-1; j<SqL->length; j++)
    {
        *(SqL->base+j) = *(SqL->base+j+1);
    }
    SqL->length--;
    return 0;
}

//按位查找动态顺序表
ElemType sq_getElem(SqList SqL, int i)
{
    if(i<0||i>SqL.length)
    {
        printf("您所查找的位置有误\n");
        return -1;
    }
    return SqL.base[i-1];
}

//按值查找动态顺序表
ElemType sq_locateElem(SqList SqL, ElemType e)
{
    for(int i=0; i<SqL.length; i++)
    {
        if(SqL.base[i] == e)
            return i+1;
    }
    printf("您所查找的值不存在\n");
    return 0;
}

//遍历动态顺序表
void sq_printList(SqList SqL)
{
    for(int i=0; i<SqL.length; i++)
    {
        if(i%5!=4)//5个数一行
        {
            printf("第%d个数 %d\t", i+1, *(SqL.base+i));
        }
        else
        {
            printf("第%d个数 %d\n", i+1, *(SqL.base+i));
            fflush(stdout);
        }
    }
    printf("\n");
    fflush(stdout);
}

//动态顺序表主调用函数
int sq_main()
{
    SqList SqL;
    sq_initList(&SqL);
    printf("\n插入元素\n");
    for(int i=0; i<10; i++){
        sq_listInsert(&SqL, i+1, i+1);
    }
    printf("插入数据前\n");
    fflush(stdout);
    sq_printList(SqL);
    int i;
    ElemType e;
    printf("请输入所插元素位置：\n");
    fflush(stdout);
    scanf("%d",&i);
    printf("请输入所要插入的元素：\n");
    fflush(stdout);
    scanf("%d",&e);
    sq_listInsert(&SqL, i, e);
    printf("插入数据后\n");
    fflush(stdout);
    sq_printList(SqL);


    printf("\n删除元素\n");
    printf("请输入所要删除元素的位置:\n");
    fflush(stdout);
    scanf("%d",&i);
    if(sq_listDelete(&SqL, i, &e)==0)
    {
        printf("已删除元素e= %d\n",e);
        fflush(stdout);
    }
    else
    {
        printf("删除失败\n");
        fflush(stdout);
    }
    sq_printList(SqL);

    printf("\n查找元素\n");
    printf("按位查找\n");
    printf("请输入所要查找元素的位置：\n");
    fflush(stdout);
    scanf("%d",&i);
    e = sq_getElem(SqL, i);
    if(e != -1)
        printf("位于%d位置的元素为 %d\n", i, e);
    printf("\n");
    printf("按值查找\n");
    printf("请输入所要查找的元素：\n");
    fflush(stdout);
    scanf("%d",&e);
    i = sq_locateElem(SqL, e);
    if(i != 0)
        printf("您所查找的元素%d位于 %d\n", e, i);
    fflush(stdout);
    return 2;
}