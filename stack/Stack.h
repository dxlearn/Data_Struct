#ifndef _Stack_H
#define _Stack_H

typedef struct node
{
    int data;
    struct node *down; 
}PNode;

typedef struct Stack
{
    PNode *top;
    int size;
}Stack;

Stack *InitStack();

void DestoryStack(Stack *ps);

void ClearStack(Stack *ps);

int IsEmpty(Stack *ps);

int GetSize(Stack *ps);

PNode *GetTop(Stack *ps,int *pitem);

PNode *Push(Stack *ps,int item);

PNode *Pop(Stack *ps,int *pitem);

void StackTraverse(Stack *ps,void (*visit)());

#endif

