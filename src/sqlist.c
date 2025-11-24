#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxSize 50

typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreateList(SqList **L, ElemType a[], int n)
{
    *L = (SqList *)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        (*L)->data[i] = a[i];
    (*L)->length = n;
}
void InitList(SqList **L)
{
    *L = (SqList *)malloc(sizeof(SqList));
    (*L)->length = 0;
}
void DestroyList(SqList *L)
{
    free(L);
}
int ListEmpty(SqList *L)
{
    return (L->length == 0);
}
int ListLength(SqList *L)
{
    return (L->length);
}
void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%c ", L->data[i]);
    printf("\n");
}
int GetElem(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return 0;
    *e = (L->data[i - 1]);
    return (1);
}
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i > L->length && L->data[i] != e)
        i++;
    if (i > L->length)
        return 0;
    else
        return (i + 1);
}
int ListInsert(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return 0;
    i--;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return 1;
}
int ListDelete(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length)
        return 0;
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return 1;
}

int main()
{
    SqList *L;
    ElemType e;
    printf("basic operations of sequence list are as follows:\n");
    printf("    (1)Initiate sequence list L\n");
    InitList(&L);
    printf("    (2)Insert a,b,c,d,e\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    printf("    (3)Display sequence list\n");
    DispList(L);
    printf("    (4)length of the sequence list:%d\n", ListLength(L));
    printf("    (5) sequence list is %s\n", (ListEmpty(L) ? "Empty" : "non-Empty"));
    GetElem(L, 3, &e);
    printf("    (6)the 3rd element of sequence list: %c\n", e);
    printf("    (7)the position of a:  %d\n", LocateElem(L, 'a'));
    DestroyList(L);
    return 1;
}