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
		QNode *ret=cur->next;
		free(cur);
		cur=ret;
	}
	pq->head=pq->tail=NULL; 
}
//-------------------------------------------- 
//-------------------------------------------- 
//上面是队列
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode *left;
//	struct BinaryTreeNode *right;
//	int data;
//}BTNode;




//利用队列，先进先出(核心思路：上一层出的时候带下一层进) 
//每次出去一个节点，就把它的左右节点入队列，最后队列为空遍历结束 
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
