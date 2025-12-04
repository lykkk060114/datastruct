#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct 
{   KeyType key;
    ElemType data;
    /* data */
}SqType;

void SelectSort(SqType R[],int n)
{
    int i,j,k;
    SqType tmp;
    for(i=0;i<n-1;i++){
        k=i;
        for (int j = i+1; j < n; j++)
        {
            if (R[j].key<R[k].key)
                k=j;   /* code */
        }
        if (k!=i)
        {
            tmp=R[i];
            R[i]=R[k];
            R[k]=tmp;
        }
        printf("i=%d:",i);
        for (int a=0; a<n; a++)
            printf("%3d",R[a].key);
        printf("\n");
    }
}
int main(){
    SqType R[MaxSize];
    KeyType A[]={75,87,68,92,88,61,77,96,80,72};
    int i,n=10;
    for(i=0;i<n;i++)
        R[i].key=A[i];
    SelectSort(R,n);
    printf("选择排序结果：");
    for (i=0;i<n;i++)
        printf("%3d",R[i].key);
    printf("\n");
    return 0;
}