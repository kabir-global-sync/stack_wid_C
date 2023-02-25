#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void push(struct Stack *stk, int ele)
{
    if (stk->top == stk->size)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stk->top++;

        stk->arr[stk->top] = ele;
    }
}

void pop(struct Stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int item;
        item = stk->arr[stk->top];
        printf("Popped item:%d\n", item);
        stk->top--;
    }
}

void traverse(struct Stack *stk)
{
    if (stk->top == -1)
    {
        printf("Empty Stack!\n");
    }
    else
    {
        printf("%d <--TOP\n", stk->arr[stk->top]);
        for (int i = stk->top - 1; i >= 10; i--)
        {
            printf("%d\n", stk->arr[i]);
        }
    }
}

int main()
{
    struct Stack *stack;
    stack->size = 5;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int)); // 20bytes are reserved

    int user;
    while (true)
    {
        printf("1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\nINPUT HERE:");
        scanf("%d", &user);

        if (user == 1)
        {
            int e;
            printf("Enter element:");
            scanf("%d", &e);
            push(stack, e);
        }
        else if (user == 2)
        {
            pop(stack);
        }
        else if (user == 3)
        {
            traverse(stack);
        }
        else
        {
            break;
        }
    }

    return 0;
}