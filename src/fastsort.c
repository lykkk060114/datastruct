/**
 * @file fastsort.c
 * @author your name (you@domain.com)
 * @brief 快速排序算法 
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct 
{   KeyType key;
    ElemType data;
    /* data */
}SqType;
int k=1;
void QuickSort(SqType R[],int s, int t)
{
    int i=s,j=t;
    SqType tmp;
    if (s<t)
    {
        tmp=R[s];
        while (i!=j)
        {
            while (j>i && R[j].key>tmp.key)
                j--;
            R[i]=R[j];
            while (i<j && R[i].key<tmp.key)
                i++;
            R[j]=R[i];
        }
        R[i]=tmp;
        printf("第%d趟排序:",k++);
        for (int a=0;a<10;a++)
            printf("%3d",R[a].key);
        printf("\n");
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
    }
}
int main()
{
    SqType R[MaxSize];
    KeyType A[]={75,87,68,92,88,61,77,96,80,72};
    int i,n=10;
    for(i=0;i<n;i++)
        R[i].key=A[i];
    QuickSort(R,0,n-1);
    printf("快速排序结果:");
    for(i=0;i<n;i++)
        printf("%3d",R[i].key);
    printf("\n");
    return 0;
}
