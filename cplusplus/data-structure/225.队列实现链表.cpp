typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue//为了方便入队（就是尾插），记录头指针和尾指针 
{
	QNode *head;
	QNode *tail; 
}Queue;

void QueueInit(Queue *pq)//初始化 
{
	assert(pq);
	pq->head=pq->tail=NULL;
} 

void QueuePush(Queue *pq,QDataType x)//队尾入 
{
	assert(pq);
	QNode *newnode=(QNode *)malloc(sizeof(QNode)*1);
	if(newnode==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data=x;
	newnode->next=NULL;
	
	if(pq->tail==NULL)
	{
		pq->head=pq->tail=newnode;//第一个节点的情况 
	}
	else//类似单链表尾插 
	{
		pq->tail->next=newnode;
		pq->tail=newnode;
	}
}

void QueuePop(Queue *pq)//队头出 
{
	assert(pq);
	assert(pq->head);
	if(pq->head->next==NULL)//只有一个节点的情况 
	{
		free(pq->head);
		pq->head=pq->tail=NULL;
	}
	else//类似单链表头删 
	{
		QNode *ret=pq->head->next;//记录head的下一个 
	    free(pq->head);
	    pq->head=ret; 
	}
}

QDataType QueueFront(Queue *pq)//取队头数据
{
	assert(pq);
	assert(pq->head);//空 
	
	return pq->head->data;
}

QDataType QueueBack(Queue *pq)//取队尾数据
{
	assert(pq);
	assert(pq->head);
	
	return pq->tail->data;
}

int QueueSize(Queue *pq)//队中数据个数
{
	assert(pq);
	int size=0;
	QNode *cur=pq->head;
	while(cur!=NULL)
	{
		size++;
		cur=cur->next;
	}
	return size;
}

bool QueueEmpty(Queue *pq)//判断是否空 
{
	assert(pq);
	return pq->head==NULL; //是空返回true;
}
 
void QueueDestory(Queue *pq)
{
	assert(pq);
	QNode *cur=pq->head;
	while(cur!=NULL)
	{
		QNode *ret=cur->next;//先保存下一个，要不然free完就找不到下一个了 
		free(cur);
		cur=ret;
	}
	pq->head=pq->tail=NULL; 
}






typedef struct 
{
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() 
{
    MyStack *ret=malloc(sizeof(MyStack));
    if(ret==NULL)
    {
        exit(-1);
    }
    QueueInit(&ret->q1);
    QueueInit(&ret->q2);
    return ret;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) 
{
    //入数据，往不为空的队列里面入
    //出数据，把不为空的队列数据导入空队列，直到只剩最后一个数据
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) 
{
    //入数据，往不为空的队列里面入
    //出数据，把不为空的队列数据导入空队列，直到只剩最后一个数据,然后删除这个数据就行了
    Queue *enptyQ=&obj->q1;//一开始假设q1为空
    Queue *nonenptyQ=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        enptyQ=&obj->q2;//如果假设错了就交换一下
        nonenptyQ=&obj->q1;
    }
    while(QueueSize(nonenptyQ) > 1)
    {
        QueuePush(enptyQ , QueueFront(nonenptyQ));//取不为空的队列数据倒倒空队列中直到剩一个
        QueuePop(nonenptyQ);
    }
    int topnumber=QueueFront(nonenptyQ);
    QueuePop(nonenptyQ);//删除剩下那一个数据

    return topnumber;
}

/** Get the top element. */
int myStackTop(MyStack* obj) 
{
    //栈顶数据就是取不为空的队列的队尾数据
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) 
{
    //两个队列权全为空，栈才为空
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    QueueDestory(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
