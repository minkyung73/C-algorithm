#include <stdio.h>
#include <stdlib.h>
#include <algorithm>    // 오류 해결하기

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

void PrintBredthFirst(treeNode *root)
{
    Queue que;
    QueueInitialize(&que);
    treeNode *temp = NULL;

    if(root != NULL)
        QueueAdd(&que, (int)root);

    while(QueueSize(&que) != 0){
        temp =(treeNode *)QueueRemove(&que);
        printf("%d ", temp->value);

        if(temp->lChild != NULL)
            QueueAdd(&que, (int)temp->lChild);
        if(temp->rChild != NULL)
            QueueAdd(&que, (int)temp->rChild);
    }
}

int main()
{
    int arr[] = {6, 4, 8, 2, 5, 7, 9, 1, 3};
    treeNode *t = levelOrderBinaryTree(arr, sizeof(arr)/sizeof(int));

    PrintBredthFirst(t);

    return 0;
}