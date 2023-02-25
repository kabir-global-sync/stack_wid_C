#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{

    char data;
    struct Node *next;
} stack;

bool pop(stack **stackTop, char* ele)
{
    stack *pDlt;
    bool success;
    if (stackTop)
    {
        success = true;
        *ele = (*stackTop)->data;
        pDlt = *stackTop;
        *stackTop = (*stackTop)->next;
        free(pDlt); // deleting the node
        printf("%c",ele);
    }
    else
    {
        success = false;
    }
    return success;
}

void print(stack **stackTop)
{
    char ele;
    while (pop(stackTop,&ele))
    {
        printf("%c",ele);
    }
}

bool push(stack **stackTop, char ele)
{
    // stackTop is holding address of the fist node
    // ele is the element to be pushed
    stack *pNew;
    bool success;
    pNew = (stack *)malloc(sizeof(stack)); // creating room for the node in the memory
    if (!pNew)
    {
        success = false;
    }
    else
    {
        pNew->data = ele;
        pNew->next = *stackTop;
        *stackTop = pNew; // stackTop points to the new node
        success = true;
    }
    return success;
}

void insertData(stack **stackTop)
{
    char ele; // element to push
    bool success;
    for (int i = 0; i < 5; i++)
    {
        ele = rand() % 26 + 'A';
        success = push(stackTop, ele);
    }
}

int main()
{
    stack *stackTop;
    stackTop = NULL;
    insertData(&stackTop);
    print(&stackTop);
    return 0;
}