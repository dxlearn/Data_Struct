#include "Stack.h"
#include <stdio.h>

void print(int i)
{
	printf("The data of this node is:%d\n",i);
}

int main()
{
    Stack *ps=InitStack();
    int i,item;

    printf("0-9 number push in stack,and print:\n");
    for(i=0;i<10;i++)
    {
        Push(ps,i);
        GetTop(ps,&item);
        printf("%d\n",item);
    }
    
    printf("------print stack------\n");
    StackTraverse(ps,print);
    printf("------Pop data------\n");
    for(i=0;i<10;i++)
    {
        Pop(ps,&item);
        printf("%d\n",item);
    }
    DestoryStack(ps);
    if(IsEmpty(ps))
    {
      printf("栈已释放\n");
    }

}