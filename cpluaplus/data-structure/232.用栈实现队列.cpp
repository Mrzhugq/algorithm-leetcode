typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;       //ջ�� 
	int capacity;  //�ռ� 
}ST;

void StackInit(ST *ps)//��ʼ�� 
{
	assert(ps);
	STDataType *temp=(STDataType*)malloc(sizeof(STDataType)*4);//�ȸ�4��������������
	if(temp==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->a=temp;
	ps->capacity=4;
	
	//ps->top=0;  //����topָ��ջ��Ԫ�ص���һ��λ��,�ȸ�ֵ��top++ 
	//ps->top=-1; //����topָ��ջ��Ԫ�أ���top++ �ڸ�ֵ
	
	ps->top=0;
}

void StackPush(ST *ps,STDataType x)//��ջ 
{
	assert(ps);
	if(ps->capacity == ps->top)//���� 
	{
		STDataType *temp=(STDataType* )realloc(ps->a,sizeof(int) * ps->capacity * 2);
		//һ�㶼��2��������
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

void StackPop(ST *ps)//��ջ 
{
	assert(ps);
	assert(ps->top > 0);//ջ�ղ��ܳ�ջ ֱ����ֹ���� 
	ps->top--;
}

STDataType StackTop(ST *ps)//ȡջ�������� 
{
	assert(ps);
	assert(ps->top > 0);//ջ�� ֱ����ֹ����
	return ps->a[ps->top-1];
}

int StackSize(ST *ps) //���ݸ��� 
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST *ps)//�ж��ǲ��ǿ� 
{
	assert(ps);
	return ps->top==0;
}

void StackDestory(ST *ps)//�ͷ� 
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
//}//��һ�������ظ��˿���д��һ������ 



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
