#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct 
{   KeyType key;
    ElemType data;
    /* data */
}SqType;
void Merge(SqType R[],int low,int mid ,int high){
    SqType *R1;
    int i=low,j=mid+1,k=0;
    R1=(SqType *)malloc((high-low+1)*sizeof(SqType));
    while (i<=mid && j<=high)
    {
      if (R[i].key<=R[j].key)
      {R1[k]=R[i];
      i++;k++;
      } else {
        R1[k]=R[j];
        j++,k++;
      }  
    }
    while (i<=mid) 
    {   R1[k]=R[i];
        i++,k++;
        /* code */
    }
    while (j<=high)
    {   R1[k]=R[j];
        j++;k++;
        /* code */
    }
    for(k=0,i=low;i<=high;k++,i++)
    {
        R[i]=R1[k];
        
    }
    free(R1);
}
void MergePass (SqType R[],int length, int n){
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)
        Merge(R,i,i+length-1,i+2*length-1);
    if(i+length-1<n)
        Merge(R,i,i+length-1,n-1);
}
void MergeSort(SqType R[],int n)
{
    int length;
    for (length=1;length<n;length=2*length)
    {
        MergePass(R,length,n);
        printf("length=%d:",length);
        for(int a=0;a<n;a++){
            printf("%3d",R[a].key);
        }
        printf("\n");
    }
}

int main()
{
    SqType R[MaxSize];
    KeyType A[]={75,87,68,92,88,61,77,96,80,72};
    int i,n=10;
    for(i=0;i<n;i++)
        R[i].key=A[i];
    MergeSort(R,n);
    printf("二路归并排序结果:");
    for(i=0;i<n;i++)
        printf("%3d",R[i].key);
    printf("\n");
    return 0;
}
