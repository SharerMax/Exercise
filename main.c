#include <stdio.h>
#include <stdlib.h>

/*************
    @description draw a rhombus
    @parameter int l: left position
    @parameter int r: right position
    @parameter int i: level counts
*************/
void rhombus(int l, int r, int i)
{
    if(i <=0)
    {
        return;
    }
    for(int m = 0; m < i; m++)
    {
        if(m == l || m == r)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        if(m+1 == i)
        {
            printf("\n");
        }
    }
    if(l == 0)
    {
        return;
    }
    rhombus(l-1, r+1, i);
    for(int m = 0; m < i; m++)
    {
        if(m == l || m == r)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        if(m+1 == i)
        {
            printf("\n");
        }
    }
}

/*************
    @description output a Rectangle with size N * N in Clockwise
    @parameter int first: first value
    @parameter int n: Rectangle size
*************/
void rect(int first, int n)
{
    int rec[10][10] = {0};
    int r=0;
    int d=0;
    int temp = first-1;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    for(int i=0; i<(n+1)/2; i++)
    {
        for(int j =i; j<n-i; j++)
        {
            r = j;
            rec[d][r] = ++temp;
        }
        temp1 = rec[d][r];
        for(int m=i+1; m<n-i; m++)
        {
            d = m;
            rec[d][r] = ++temp1;

        }
        temp2 = rec[d][r];
        for(int x=r-1; x>=i; x--)
        {
            rec[d][x] = ++temp2;
            r = x;
        }
        temp3=rec[d][r];
        for(int y=d-1; y>i; y--)
        {
            rec[y][r] = ++temp3;
            d = y;
        }
        temp = rec[d][r];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%2d ", rec[i][j]);
        }
        printf("\n");
    }
}

/*******************
    @description 楼梯有N（小于50的整数）阶，上楼可以一步上一价，也可以一次上二阶。
                编一个程序，计算共有多少种不同的走法。(递归实现)
    @parameter  int n 楼梯阶数
********************/
int upstairs(int n)
{
    if(1 == n) {
        return 1;
    }

    if(2 == n) {
        return 2;
    }

    return upstairs(n-1) + upstairs(n-2);
}


struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

//先序生成二叉树
struct BinaryTreeNode* generateTree()
{
    int value;
    struct BinaryTreeNode *root;
    scanf_s("%d", &value);
    if(0 == value) return NULL;
    root = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    root->value = value;
    root->left = generateTree();
    root->right = generateTree();
    return root;
}
//先序遍历二叉树
void pOrder(struct BinaryTreeNode *root)
{
    if(NULL == root) return;
    printf("%d ", root->value);
    pOrder(root->left);
    pOrder(root->right);
}
//中序遍历二叉树
void mOrder(struct BinaryTreeNode *root)
{
    if(NULL == root) return;
    mOrder(root->left);
    printf("%d ", root->value);
    mOrder(root->right);

}
//后序遍历二叉树
void aOrder(struct BinaryTreeNode *root)
{
    if(NULL == root) return;
    aOrder(root->left);
    aOrder(root->right);
    printf("%d ", root->value);
}
//递归实现二叉树左、右支交换（翻转二叉树）
void invertTree(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *swap;
	if (NULL == root) return;
	swap = root->left;
	root->left = root->right;
	root->right = swap;
	invertTree(root->left);
	invertTree(root->right);
}
void binaryTree()
{
    struct BinaryTreeNode *root;
    root = generateTree();
    pOrder(root);
    printf("\n");
    mOrder(root);
    printf("\n");
    aOrder(root);
	printf("\n");
	invertTree(root);
	pOrder(root);

}

int main()
{
    int n = 0;
    //scanf_s("%d", &n);
   // rhombus(times-1, times-1, 2*times -1);
    //rect(1, times/2, times, times);
    //rect(1, n);
    //printf("%d", upstairs(n));
    binaryTree();
	
    return 0;
}
