#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
/**
 * @brief 二叉树的遍历
 * @author lyk 20251110
 *
 */
typedef char ElemType;
typedef struct tnode
{
    /* data */
    ElemType data;
    struct tnode *lchild, *rchild;
} BTNode;

void CreateBTree(BTNode **bt, const char *str)
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    *bt = NULL; // 初始化根指针

    ch = str[j];
    while (ch != '\0') // 以字符串结束符为结束条件
    {
        switch (ch)
        {
        case '(': // 进入子树，当前结点入栈
            top++;
            St[top] = p;
            k = 1; // 下一个结点先连到左孩子
            break;
        case ')': // 当前子树结束，栈顶弹出
            top--;
            break;
        case ',': // 接下来应该连到右孩子
            k = 2;
            break;
        default: // 普通结点字符
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (*bt == NULL) // 还没有根结点时，当前结点就是根
                *bt = p;
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p; // 接到左孩子
                    break;
                case 2:
                    St[top]->rchild = p; // 接到右孩子
                    break;
                }
            }
            break;
        }
        j++;
        ch = str[j];
    }
}

void PreOrder(BTNode *bt)
{
    if (bt != NULL)
    {
        printf("%c", bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
void InOrder(BTNode *bt)
{
    if (bt != NULL)
    {
        InOrder(bt->lchild);
        printf("%c", bt->data);
        InOrder(bt->rchild);
    }
}
void PostOrder(BTNode *bt)
{
    if (bt != NULL)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%c", bt->data);
    }
}
void LevelOrder(BTNode *bt)
{
    BTNode *p;
    BTNode *qu[MaxSize];
    int front, rear;
    front = rear = -1;
    rear++;
    qu[rear] = bt;
    while (front != rear)
    {
        front = (front + 1) % MaxSize;
        p = qu[front];
        printf("%c", p->data);
        if (p->lchild != NULL)
        {
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->lchild;
        }
        if (p->rchild != NULL)
        {
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->rchild;
        }
    }
}
void DispBTree(BTNode *bt)
{
    if (bt != NULL)
    {
        printf("%c", bt->data);
        if (bt->lchild != NULL || bt->rchild != NULL)
        {
            printf("(");
            DispBTree(bt->lchild);
            if (bt->rchild != NULL)
                printf(",");
            DispBTree(bt->rchild);
            printf(")");
        }
    }
}

void DestroyBTree(BTNode **bt)
{
    if (*bt != NULL)
    {
        DestroyBTree(&((*bt)->lchild));
        DestroyBTree(&((*bt)->rchild));
        free(*bt);
        *bt = NULL; // 防止悬空指针
    }
}
int main()
{
    BTNode *bt;
    CreateBTree(&bt, "A(B(D,E(G,H)),C(,F(I)))");
    printf("二叉树bt:");
    DispBTree(bt);
    printf("\n");
    printf("先序遍历序列");
    PreOrder(bt);
    printf("\n");
    printf("中序遍历序列：");
    InOrder(bt);
    printf("\n");
    printf("后序遍历序列：");
    PostOrder(bt);
    printf("\n");
    printf("层次遍历序列：");
    LevelOrder(bt);
    printf("\n");
    DestroyBTree(&bt);
    return 0;
}