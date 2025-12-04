#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType data;
}Rectype;
void CreateList(Rectype R[], KeyType keys[], int n)
{
    for(int i=0; i<n ; i++)
        R[i].key=keys[i];
}
void DispList(Rectype R[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
}
int BinSearch(Rectype R[],int n, KeyType k)
{
    int low=0,high=n-1,mid,count=0;
    while (low<=high)
    {
        mid=(low+high)/2;
        printf("第%d次比较:在[%d, %d]中比较元素 R[%d]: %d\n",++count,low,high,mid,R[mid].key);
        if(R[mid].key==k)
            return mid+1;
        if(R[mid].key>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
// int BinSearch(Rectype R[], KeyType k, int low, int high)
// {
//     int mid;
//     if(low>high)
//         return(-1);
//     else{
//         mid=(low+high)/2;
//         if(k==R[mid].key)
//             return(mid);
//         else if(k>R[mid].key)
//             return(BinSearch(R,k,mid+1,high));
//         else
//             return(BinSearch(R,k,low,mid-1));
//     }
// }
int main(){
    Rectype R[MAXL];
    KeyType k=9;
    int a[]={2,4,7,9,10,13,18,26,32,49},i,n=10;
    CreateList(R,a,n);
    printf("关键字序列："); DispList(R,n);
    printf("查找%d的比较过程如下:\n",k);
    if(-1!=(i=BinSearch(R,n,k)))
        printf("元素%d的位置是%d\n",k,i);
    else
        printf("元素%d不在表中\n",k);

    return 1;
}