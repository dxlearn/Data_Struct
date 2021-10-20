#include <stdio.h>
#include "Stack.h"
#include <malloc.h>
#include <stdlib.h>

//栈初始化
Stack *InitStack()
{
    Stack *ps;
    //分配栈空间
    ps=(Stack *)malloc(sizeof(Stack));
    if(ps!=NULL)
    {
        ps->top=NULL;//栈顶为空
        ps->size=0; //栈空时：大小为0
    }

    return ps;//返回栈空间的首地址
}

void DestoryStack(Stack *ps)
{
    if(IsEmpty(ps)!=1)
       ClearStack(ps);
    free(ps);//释放栈空间
}

void ClearStack(Stack *ps)
{
    //只要栈不为空，就一直出栈
    while (IsEmpty(ps)!=1)
    {
        Pop(ps,NULL);
    }
    
}

int IsEmpty(Stack *ps)
{
    //栈顶为空或者栈大小为0时为空栈
    if (ps->top==NULL &&ps->size==0)
    {
        return 1;
    }
    
}

int Getsize(Stack *ps)
{
    return ps->size;
}


PNode *GetTop(Stack *ps,int *pitem)
{
    if(IsEmpty(ps)!=1 && pitem!=NULL)
    {
         //得到top对应的数值
        *pitem=ps->top->data;

    }
    return ps->top;
}


//入栈
PNode *Push(Stack *ps,int item)
{
    //创建节点
    PNode *pnode = (PNode *)malloc(sizeof(PNode));
    if(pnode!=NULL)
    {
        //节点数据
        pnode->data=item;
        pnode->down=GetTop(ps,NULL);//栈顶下一个元素是当前的top
        ps->size++;//更新栈的大小：+1
        ps->top=pnode;//更新栈顶指针：当前入栈的节点
    }
    return pnode;
}


//出栈
PNode *Pop(Stack *ps,int *pitem)
{
    PNode *pnode=ps->top;//获得出栈节点
    if (IsEmpty(ps)!=1 &&pnode!=NULL)
    {
        if(pitem!=NULL)
        *pitem=pnode->data;//获取出栈节点的数据
        ps->size--;  //栈大小：-1
        ps->top=ps->top->down;//更新栈顶指针：出栈节点的down
    }
    return ps->top;   //返回最新的栈顶指针

}



void StackTraverse(Stack *ps,void(*visit)())
{
    PNode *p=ps->top; //获取栈顶节点
    int i=ps->size;   //获取当前栈的大小
    while (i--)
    {
        visit(p->data);//打印元素 从栈顶开始打印
        p=p->down;     
    }
    
}







