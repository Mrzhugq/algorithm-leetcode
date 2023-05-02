#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	int data;
}BTNode;

typedef BTNode* QDataType;
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
		QNode *ret=cur->next;
		free(cur);
		cur=ret;
	}
	pq->head=pq->tail=NULL; 
}
//-------------------------------------------- 
//-------------------------------------------- 
//�����Ƕ���
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode *left;
//	struct BinaryTreeNode *right;
//	int data;
//}BTNode;




//���ö��У��Ƚ��ȳ�(����˼·����һ�����ʱ�����һ���) 
//ÿ�γ�ȥһ���ڵ㣬�Ͱ��������ҽڵ�����У�������Ϊ�ձ������� 
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	
	if(root != NULL)
	{
		QueuePush(&q,root);
	}
	while(!QueueEmpty(&q))
	{
		BTNode *front=QueueFront(&q);
		QueuePop(&q);
		printf("%c ",front->data);
		
		if(front->left!=NULL)
		{
			QueuePush(&q,front->left);
		}
		if(front->right!=NULL)
		{
			QueuePush(&q,front->right);
		}
	}
	printf("\n");
	QueueDestory(&q);
}



int main()
{
	BTNode *A=(BTNode*)malloc(sizeof(BTNode)*1);
	A->data='A';
	A->left=NULL;
	A->right=NULL;
	
	BTNode *B=(BTNode*)malloc(sizeof(BTNode)*1);
	B->data='B';
	B->left=NULL;
	B->right=NULL;
	
	BTNode *C=(BTNode*)malloc(sizeof(BTNode)*1);
	C->data='C';
	C->left=NULL;
	C->right=NULL;
	
	BTNode *D=(BTNode*)malloc(sizeof(BTNode)*1);
	D->data='D';
	D->left=NULL;
	D->right=NULL;
	
	BTNode *E=(BTNode*)malloc(sizeof(BTNode)*1);
	E->data='E';
	E->left=NULL;
	E->right=NULL;
	
	A->left=B;
	A->right=C;
	B->left=D;
	B->right=E;
	
	LevelOrder(A);
} 
