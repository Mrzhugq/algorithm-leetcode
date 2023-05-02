#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//���нṹһ���õ�����ʵ�ֱȽϺ� (���нṹ�Ƚ��ȳ�������߳���Ӱ��˳��) 
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
	return pq->head==NULL; 
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
	
	while(!QueueEmpty(&q))//����ȥ������ֻ��������ɾ�߳�
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
	return 0;
}
