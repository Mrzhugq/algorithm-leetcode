#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//队列结构一般用单链表实现比较好 (队列结构先进先出，边入边出不影响顺序) 
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
	return pq->head==NULL; 
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




//void TestQueue()
//{
//
//}
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q,4);
	
	while(!QueueEmpty(&q))//不能去遍历，只能这样边删边出
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
	return 0;
}
