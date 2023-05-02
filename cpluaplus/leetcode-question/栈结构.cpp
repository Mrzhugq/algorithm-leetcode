#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//栈结构一般用数组实现比较好 (栈结构先进后出，边入边出影响顺序) 
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;       //栈顶 
	int capacity;  //空间 
}ST;

void StackInit(ST *ps)//初始化 
{
	assert(ps);
	STDataType *temp=(STDataType*)malloc(sizeof(STDataType)*4);//先给4个，不够在增容
	if(temp==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->a=temp;
	ps->capacity=4;
	
	//ps->top=0;  //这样top指向栈顶元素的下一个位置,先赋值在top++ 
	//ps->top=-1; //这样top指向栈顶元素，先top++ 在赋值
	
	ps->top=0;
}

void StackPush(ST *ps,STDataType x)//入栈 
{
	assert(ps);
	if(ps->capacity == ps->top)//满了 
	{
		STDataType *temp=(STDataType* )realloc(ps->a,sizeof(int) * ps->capacity * 2);
		//一般都是2倍的扩容
		if(temp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a=temp;
			ps->capacity=ps->capacity*2;
		}
	}
	
	ps->a[ps->top]=x;
	ps->top++; 
}

void StackPop(ST *ps)//出栈 
{
	assert(ps);
	assert(ps->top > 0);//栈空不能出栈 直接终止程序 
	ps->top--;
}

STDataType StackTop(ST *ps)//取栈顶的数据 
{
	assert(ps);
	assert(ps->top > 0);//栈空 直接终止程序
	return ps->a[ps->top-1];
}

int StackSize(ST *ps) //数据个数 
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST *ps)//判断是不是空 
{
	assert(ps);
	return ps->top==0;
}



void StackDestory(ST *ps)//释放 
{
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity=ps->top=0;
}



int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st,2);
	StackPush(&st,3);
	StackPush(&st,4);
	
	while(!StackEmpty(&st))//不能去遍历，只能这样边删边出 
	{
		printf("%d ",StackTop(&st));
		StackPop(&st);
    }
    
	StackDestory(&st);
	return 0;
}
