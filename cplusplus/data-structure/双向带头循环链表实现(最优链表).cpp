#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType; 
//˫���ͷѭ������STL��һ����   ->��������ṹ������λ�ò���ɾ������O(1),������O(n) 
//���߽� DListNode                            
typedef struct ListNode  
{ 
    LTDataType data;
    struct ListNode *next;
	struct ListNode *prev; 
}ListNode;



ListNode* BuyListNode(LTDataType x)//����һ���½ڵ㺯��
{
	ListNode *newnode=(ListNode*)malloc(sizeof(ListNode)*1);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
} 

ListNode* ListInit(ListNode *phead)//��ʼ������ 
{
	phead=BuyListNode(0);
	phead->next=phead;//��ָ���Լ� 
	phead->prev=phead;
	return phead; 
}

void ListPushBack(ListNode *phead,LTDataType x)//β������ 
{
	assert(phead);
	ListNode* tail=phead->prev; //β�ڵ� tail
	ListNode* newnode=BuyListNode(x);
	
	tail->next=newnode;//����Ϊ��Ϊ�ն���ʵ�ֲ��룬�뵥����һ�����������Ҫ�ֿ����� 
	newnode->prev=tail;
	newnode->next=phead;
	phead->prev=newnode; 
}//����ֱ�Ӹ��������ListInsert(phead,LTDataType x);

void ListPushFront(ListNode *phead,LTDataType x)//ͷ������
{
	assert(phead);
	ListNode *first=phead->next;//ͷ����ڵ�
	ListNode *newnode=BuyListNode(x);
	
	phead->next=newnode;//�����д���˳����Ի������û��first�洢��Ҫע��˳���ˣ�������� 
	newnode->next=first;
	newnode->prev=phead;
	first->prev=newnode; 
}//����ֱ�Ӹ��������ListInsert(phead->next,LTDataType x);

void ListPopBack(ListNode *phead)//βɾ����
{
	assert(phead);
	assert(phead->next!=phead);   //��ֹֻ��һ��ͷ�ڵ㣬��ͷ�ڵ�free�� 
	ListNode *tail=phead->prev;   //β�ڵ� 
	ListNode *ret=tail->prev;    //βǰһ���ڵ�
	
	ret->next=phead;
	phead->prev=ret;
	free(tail);
	tail=NULL;
} //����ֱ�Ӹ�������� ListErase(phead->prev);

void ListPopFront(ListNode *phead)//ͷɾ���� (ɾ����Ҳû��)
{
	assert(phead);
	assert(phead->next!=phead);   //��ֹֻ��һ��ͷ�ڵ㣬��ͷ�ڵ�free�� 
	ListNode *first=phead->next;  //ͷ�����һ���ڵ� 
	ListNode *second=first->next; //ͷ����ڶ����ڵ�
	
	phead->next=second;
	second->prev=phead;
	free(first);
	first=NULL;
} //����ֱ�Ӹ�������� ListErase(phead->next);

void Listprint(ListNode *phead)//��ӡ 
{
	ListNode *cur=phead->next;//ͷ����ӡ
	while(cur!=phead)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	} 
	printf("\n");
}

ListNode *ListFind(ListNode *phead,LTDataType x)//���ҽڵ㺯�� (ֻҪ�ҵ�����ֱ�Ӹ�) 
{
	assert(phead);
	ListNode *cur=phead->next;//ͷ���濪ʼ���� 
	while(cur!=phead)
	{
		if(cur->data==x)
		{
			return cur;
		}
		cur=cur->next;
	}
	return NULL;
}

void ListInsert(ListNode *pos,LTDataType x)//��posλ��֮ǰ����x 
{
	assert(pos); 
	ListNode *ret=pos->prev;//posǰһ���ڵ� 
	ListNode *newnode=BuyListNode(x);
	
	ret->next=newnode;
	newnode->next=pos;
	newnode->prev=ret;
	pos->prev=newnode;
}

void ListErase(ListNode *pos)//ɾ��posλ�õ�ֵ
{
	assert(pos);
	ListNode *ago=pos->prev;//pos��ǰһ���ڵ� 
	ListNode *after=pos->next;//pos�ĺ�һ���ڵ�
	
	ago->next=after;
	after->prev=ago;
	free(pos);
	pos=NULL;
} 

void ListDestory(ListNode *phead)//�ͷź��� 
{
	assert(phead);
	ListNode *cur=phead->next;
	while(cur!=phead)
	{
		ListNode *after=cur->next;
		free(cur);
		cur=after;
	} 
	
	free(phead);
	phead=NULL; 
}
//bool ListEmpt(ListNode *phead) //�ж������ǲ��ǿպ��� 
//{
//	
//}
//int ListSize(ListNode *phead) //�����Ⱥ���
//{
//	
//} 


void TestList1()
{
    ListNode *plist=ListInit(plist);
    
	ListPushBack(plist,1);//β����� 
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	Listprint(plist);
	
	ListPushFront(plist,9);//ͷ����� 
	ListPushFront(plist,8);
	ListPushFront(plist,7);
	Listprint(plist);
	
	ListPopBack(plist);//βɾ���� 
	ListPopBack(plist);
	Listprint(plist);
	
	ListPopFront(plist);//ͷɾ���� 
	ListPopFront(plist);
	Listprint(plist);
	
	ListDestory(plist);
} 

void TestList2()
{
	ListNode *plist=ListInit(plist);
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	Listprint(plist);
	
	ListNode *pos=ListFind(plist,3);//ֻҪ�ҵ�����ֱ�Ӹ� 
	if(pos!=NULL)
	{
		//���ң������޸ĵ����� 
		pos->data*=10;
		printf("�ҵ���,���ҰѸýڵ��ֵ��10\n"); 
	}
	else
	{
		printf("û�ҵ�\n");
	}
	Listprint(plist);
	
	ListInsert(pos,300);//ָ��λ�ò������ 
	Listprint(plist);
	
	ListErase(pos);//ָ��λ��ɾ������ 
	Listprint(plist);
	
	ListDestory(plist);
}

int main()
{
	//TestList1();
	TestList2();
} 
