#include <stdio.h>
#include <stdlib.h>

typedef struct tNode
{
    int value;
    struct tNode *lChild;
    struct tNode *rChild;
}treeNode;

treeNode *levelOrderBinaryTreeUtil(int arr[], int size, int start)
{
    treeNode *curr = (treeNode *)malloc(sizeof(treeNode));
    curr->value = arr[start];
    curr->lChild = curr->rChild = NULL;
    int left = 2*start + 1;
    int right = 2*start + 2;

    if(left < size)
        curr->lChild = levelOrderBinaryTreeUtil(arr, size, left);
    if(right < size)
        curr->rChild = levelOrderBinaryTreeUtil(arr, size, right);

    return curr;
}

treeNode *levelOrderBinaryTree(int arr[], int size)
{
    return levelOrderBinaryTreeUtil(arr, size, 0);
}

int treeDepth(treeNode *root)
{
    if(!root)
        return 0;
    else{
        int lDepth = treeDepth(root->lChild);
        int rDepth = treeDepth(root->rChild);

        if(lDepth>rDepth)
            return lDepth + 1;
        else
            return rDepth + 1;
    }
}

int main()
{
    int arr[] = {6, 4, 8, 2, 5, 7, 9, 1, 3};
    treeNode *t = levelOrderBinaryTree(arr, sizeof(arr)/sizeof(int));

    printf("%d", treeDepth(t));

    return 0;
}