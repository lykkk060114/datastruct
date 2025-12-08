#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;  
typedef struct LNode
{
    ElemType data;
    struct LNode *next; 
} LinkNode; //64位对齐以后16字节 
/**认真体会了C++和C结构体的不一样
认真体会结构体才发现面向对象的思想从结构体就能体会的淋漓尽致
一个链表是不能在一开始就规划内存大小的，不过说到 vector,
倒是也可以从顺序表知道他的问题所在，感觉还是知识浅薄，stl容器仅仅知道一个接口还是远远不够的
过段时间会去尝试用容器来完成数据结构，可能又会有其他感受了
/
/**
 * @brief 初始化一个节点罢了
 * @details 如果单层指针 就是把结构体指针给复制进去了，然后这个一切都是对复制的指针进行，并非这个指针本身，只有把这个指针的地址传进去才准确
 * @param L 
 */
void InitList(LinkNode **L)
{
    (*L) = (LinkNode *)malloc(sizeof(LinkNode));    //先创建一个指针实例（分配空间）
    (*L)->next = NULL;      //再防止指针悬空
}
/**
 * @brief 
 * 
 * @param L 
 */
void DestoryList(LinkNode **L)
{
    LinkNode *pre = *L, *p = pre->next; //两个并排指针 一个是头指针的拷贝，一个是下一个指针的拷贝 只能慢慢理解，没想到怎么解释
    while (p != NULL)
    {
        free(pre);      
        pre = p;    
        p = pre->next;      
    }
    free(pre);
}
int ListEmpty(LinkNode *L)      
{
    return (L->next == NULL);
}
int ListLength(LinkNode *L)  
{
    int i = 0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return (i);
}
void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%c  ", p->data);
        p = p->next;
    }
    printf("\n");
}
int GetElem(LinkNode *L, int i, ElemType *e)
{
    int j = 0;
    LinkNode *p = L;
    if (i < 0)
        return 0;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    else
    {
        *e = p->data;
        return 1;
    }
}
int LocateElem(LinkNode *L, ElemType e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0;
    else
    {
        return (i);
    }
}
int ListInsert(LinkNode *L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return 0;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}
int ListDelete(LinkNode *L, int i, ElemType *e)
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i < 0)
        return 0;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        q = p->next;
        if (q == NULL)
            return 0;
        *e = q->data;
        p->next = q->next;
        free(q);
        return 1;
    }
}
int main()
{
    LinkNode *h; //其实一个带头节点也不错，但是一个无头指针更像是这个结构
    ElemType e;
    printf("单链表的基本运算：\n");
    printf("(1)初始化单链表h\n");
    InitList(&h);
    printf("(2)依次使用尾插法插入a、b、c,d,e元素\n");
    ListInsert(h, 1, 'a');
    ListInsert(h, 2, 'b');
    ListInsert(h, 3, 'c');
    ListInsert(h, 4, 'd');
    ListInsert(h, 5, 'e');
    printf("(3)输出单链表h:");
    DispList(h);
    printf("(4)单链表长度：%d\n", ListLength(h));
    // 修正后的代码 - 使用英文引号
    printf("(5)单链表h为：%s\n", (ListEmpty(h) ? "空" : "非空"));
    GetElem(h, 3, &e);
    printf("(6)单链表h的第三个元素：%c\n", e);
    printf("(7)元素a的位置：%d\n", LocateElem(h, 'a'));
    printf("(8)在第4个元素位置上插入元素f\n");
    ListInsert(h, 4, 'f');
    printf("(9)输出单链表h:");
    DispList(h);
    printf("(10)删除h的第三个元素\n");
    ListDelete(h, 3, &e);
    printf("(11)输出单链表h:\n");
    DispList(h);
    printf("(12)释放单链表h\n");
    DestoryList(&h);
    return 1;
}