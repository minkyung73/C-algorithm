#include <stdio.h>
#define MAX_CAPACITY 100
#define ERROR_VALUE 404

typedef struct stack
{
    int top;
    int data[MAX_CAPACITY];
}Stack;

void StackInitialize(Stack *stk)
{
    stk->top = -1;
}

// 스택이 비어 있으면 1을 반환, 나머지 경우에는 0을 반환
int StackIsEmpty(Stack *stk)
{
    return (stk->top == -1);
}

// 스택 내 원소의 개수 반환
int StackSize(Stack *stk)
{
    return (stk->top + 1);
}

// 배열의 원소 출력 (꼭대기에서부터)
void StackPrint(Stack *stk)
{
    printf("Stack :: ");
    for(int i=stk->top ; i>=0 ; i--)
        printf("%d ", stk->data[i]);

    printf("\n");
}

// push
void StackPush(Stack *stk, int value)
{
    if(stk->top < MAX_CAPACITY - 1){
        stk->top++;
        stk->data[stk->top] = value;
    }
    else{
        printf("stack overflow\n");
    }
}

// pop
int StackPop(Stack *stk)
{
    if (stk->top >= 0){
        int value = stk->data[stk->top];
        stk->top--;
        return value;
    }
    printf("stack empty\n");
    return ERROR_VALUE;
}

// 스택 꼭대기 워소에 저장된 값을 반환 (삭제x)
int StackTop(Stack *stk)
{
    int value = stk->data[stk->top];
    return value;
}

int main()
{
    Stack stk;
    StackInitialize(&stk);
    StackPush(&stk, 1);
    StackPush(&stk, 2);
    StackPush(&stk, 3);
    StackPush(&stk, 4);
    StackPush(&stk, 5);
    StackPrint(&stk);

    StackPop(&stk);
    StackPrint(&stk);
}