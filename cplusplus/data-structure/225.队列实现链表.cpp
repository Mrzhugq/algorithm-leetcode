typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue//Ϊ�˷�����ӣ�����β�壩����¼ͷָ���βָ�� 
{
	QNode *head;
	QNode *tail; 
}Queue;

void QueueInit(Queue *pq)//��ʼ�� 
{
	assert(pq);
	pq->head=pq->tail=NULL;
} 

void QueuePush(Queue *pq,QDataType x)//��β�� 
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
		pq->head=pq->tail=newnode;//��һ���ڵ����� 
	}
	else//���Ƶ�����β�� 
	{
		pq->tail->next=newnode;
		pq->tail=newnode;
	}
}

void QueuePop(Queue *pq)//��ͷ�� 
{
	assert(pq);
	assert(pq->head);
	if(pq->head->next==NULL)//ֻ��һ���ڵ����� 
	{
		free(pq->head);
		pq->head=pq->tail=NULL;
	}
	else//���Ƶ�����ͷɾ 
	{
		QNode *ret=pq->head->next;//��¼head����һ�� 
	    free(pq->head);
	    pq->head=ret; 
	}
}

QDataType QueueFront(Queue *pq)//ȡ��ͷ����
{
	assert(pq);
	assert(pq->head);//�� 
	
	return pq->head->data;
}

QDataType QueueBack(Queue *pq)//ȡ��β����
{
	assert(pq);
	assert(pq->head);
	
	return pq->tail->data;
}

int QueueSize(Queue *pq)//�������ݸ���
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

bool QueueEmpty(Queue *pq)//�ж��Ƿ�� 
{
	assert(pq);
	return pq->head==NULL; //�ǿշ���true;
}
 
void QueueDestory(Queue *pq)
{
	assert(pq);
	QNode *cur=pq->head;
	while(cur!=NULL)
	{
		QNode *ret=cur->next;//�ȱ�����һ����Ҫ��Ȼfree����Ҳ�����һ���� 
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
    //�����ݣ�����Ϊ�յĶ���������
    //�����ݣ��Ѳ�Ϊ�յĶ������ݵ���ն��У�ֱ��ֻʣ���һ������
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
    //�����ݣ�����Ϊ�յĶ���������
    //�����ݣ��Ѳ�Ϊ�յĶ������ݵ���ն��У�ֱ��ֻʣ���һ������,Ȼ��ɾ��������ݾ�����
    Queue *enptyQ=&obj->q1;//һ��ʼ����q1Ϊ��
    Queue *nonenptyQ=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        enptyQ=&obj->q2;//���������˾ͽ���һ��
        nonenptyQ=&obj->q1;
    }
    while(QueueSize(nonenptyQ) > 1)
    {
        QueuePush(enptyQ , QueueFront(nonenptyQ));//ȡ��Ϊ�յĶ������ݵ����ն�����ֱ��ʣһ��
        QueuePop(nonenptyQ);
    }
    int topnumber=QueueFront(nonenptyQ);
    QueuePop(nonenptyQ);//ɾ��ʣ����һ������

    return topnumber;
}

/** Get the top element. */
int myStackTop(MyStack* obj) 
{
    //ջ�����ݾ���ȡ��Ϊ�յĶ��еĶ�β����
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
    //��������ȨȫΪ�գ�ջ��Ϊ��
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
