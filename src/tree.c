#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
/**
 * @brief
 * @author lyk 20251110
 */
typedef char ElemType;

typedef struct tnode
{
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

int BTHeight(BTNode *bt)
{
    int lchilddep, rchilddep;
    if (bt == NULL)
        return 0;
    else
    {
        lchilddep = BTHeight(bt->lchild);
        rchilddep = BTHeight(bt->rchild);
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

int NodeCount(BTNode *bt)
{
    int num1, num2;
    if (bt == NULL)
        return 0;
    else
    {
        num1 = NodeCount(bt->lchild);
        num2 = NodeCount(bt->rchild);
        return (num1 + num2 + 1);
    }
}

int LeafCount(BTNode *bt)
{
    int num1, num2;
    if (bt == NULL)
        return 0;
    else if (bt->lchild == NULL && bt->rchild == NULL)
        return 1;
    else
    {
        num1 = LeafCount(bt->lchild);
        num2 = LeafCount(bt->rchild);
        return (num1 + num2);
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
/**
 * @brief main
 *
 * @return int
 */
int main()
{
    BTNode *bt; // 创建结构体指针
    CreateBTree(&bt, "A(B(D,E(G,H)),C(,F(I)))");
    printf("二叉树bt:");
    DispBTree(bt);
    printf("\n");
    printf("bt的高度:%d\n", BTHeight(bt));
    printf("bt的结点数:%d\n", NodeCount(bt));
    printf("bt的叶子结点数:%d\n", LeafCount(bt));
    printf("销毁二叉树 bt\n");
    DestroyBTree(&bt);
    return 0;
}
