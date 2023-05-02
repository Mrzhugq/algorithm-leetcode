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









typedef struct 
{
    ST pushST;
    ST popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() 
{
    MyQueue* dummy=(MyQueue* )malloc(sizeof(MyQueue));
    StackInit(&dummy->pushST);
    StackInit(&dummy->popST);
    return dummy;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) 
{
    StackPush(&obj->pushST,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) 
{
    if(StackEmpty(&obj->popST))
    {
        while(!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST , StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    
    int ret=StackTop(&obj->popST);
    StackPop(&obj->popST);
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) 
{
    if(StackEmpty(&obj->popST))
    {
        while(!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST , StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }

    return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) 
{
    return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj) 
{
    StackDestory(&obj->pushST);
    StackDestory(&obj->popST);
    free(obj);
}


//while(!StackEmpty(&obj->pushST))
//{
//    StackPush(&obj->popST , StackTop(&obj->pushST));
//    StackPop(&obj->pushST);
//}//这一段上面重复了可以写出一个函数 



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
