#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType; 
//双向带头循环链表（STL中一样）   ->最优链表结构，任意位置插入删除都是O(1),查找是O(n) 
//或者叫 DListNode                            
typedef struct ListNode  
{ 
    LTDataType data;
    struct ListNode *next;
	struct ListNode *prev; 
}ListNode;



ListNode* BuyListNode(LTDataType x)//创建一个新节点函数
{
	ListNode *newnode=(ListNode*)malloc(sizeof(ListNode)*1);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
} 

ListNode* ListInit(ListNode *phead)//初始化函数 
{
	phead=BuyListNode(0);
	phead->next=phead;//先指向自己 
	phead->prev=phead;
	return phead; 
}

void ListPushBack(ListNode *phead,LTDataType x)//尾插数据 
{
	assert(phead);
	ListNode* tail=phead->prev; //尾节点 tail
	ListNode* newnode=BuyListNode(x);
	
	tail->next=newnode;//链表为不为空都能实现插入，与单链表不一样，这个不需要分开考虑 
	newnode->prev=tail;
	newnode->next=phead;
	phead->prev=newnode; 
}//可以直接复用下面的ListInsert(phead,LTDataType x);

void ListPushFront(ListNode *phead,LTDataType x)//头插数据
{
	assert(phead);
	ListNode *first=phead->next;//头后面节点
	ListNode *newnode=BuyListNode(x);
	
	phead->next=newnode;//这四行代码顺序可以换，如果没有first存储就要注意顺序了，先连后断 
	newnode->next=first;
	newnode->prev=phead;
	first->prev=newnode; 
}//可以直接复用下面的ListInsert(phead->next,LTDataType x);

void ListPopBack(ListNode *phead)//尾删数据
{
	assert(phead);
	assert(phead->next!=phead);   //防止只有一个头节点，把头节点free掉 
	ListNode *tail=phead->prev;   //尾节点 
	ListNode *ret=tail->prev;    //尾前一个节点
	
	ret->next=phead;
	phead->prev=ret;
	free(tail);
	tail=NULL;
} //可以直接复用下面的 ListErase(phead->prev);

void ListPopFront(ListNode *phead)//头删数据 (删到空也没事)
{
	assert(phead);
	assert(phead->next!=phead);   //防止只有一个头节点，把头节点free掉 
	ListNode *first=phead->next;  //头后面第一个节点 
	ListNode *second=first->next; //头后面第二个节点
	
	phead->next=second;
	second->prev=phead;
	free(first);
	first=NULL;
} //可以直接复用下面的 ListErase(phead->next);

void Listprint(ListNode *phead)//打印 
{
	ListNode *cur=phead->next;//头不打印
	while(cur!=phead)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	} 
	printf("\n");
}

ListNode *ListFind(ListNode *phead,LTDataType x)//查找节点函数 (只要找到就能直接改) 
{
	assert(phead);
	ListNode *cur=phead->next;//头后面开始查找 
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

void ListInsert(ListNode *pos,LTDataType x)//在pos位置之前插入x 
{
	assert(pos); 
	ListNode *ret=pos->prev;//pos前一个节点 
	ListNode *newnode=BuyListNode(x);
	
	ret->next=newnode;
	newnode->next=pos;
	newnode->prev=ret;
	pos->prev=newnode;
}

void ListErase(ListNode *pos)//删除pos位置的值
{
	assert(pos);
	ListNode *ago=pos->prev;//pos的前一个节点 
	ListNode *after=pos->next;//pos的后一个节点
	
	ago->next=after;
	after->prev=ago;
	free(pos);
	pos=NULL;
} 

void ListDestory(ListNode *phead)//释放函数 
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
//bool ListEmpt(ListNode *phead) //判断链表是不是空函数 
//{
//	
//}
//int ListSize(ListNode *phead) //链表长度函数
//{
//	
//} 


void TestList1()
{
    ListNode *plist=ListInit(plist);
    
	ListPushBack(plist,1);//尾插测试 
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	Listprint(plist);
	
	ListPushFront(plist,9);//头插测试 
	ListPushFront(plist,8);
	ListPushFront(plist,7);
	Listprint(plist);
	
	ListPopBack(plist);//尾删测试 
	ListPopBack(plist);
	Listprint(plist);
	
	ListPopFront(plist);//头删测试 
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
	
	ListNode *pos=ListFind(plist,3);//只要找到就能直接改 
	if(pos!=NULL)
	{
		//查找，附带修改的作用 
		pos->data*=10;
		printf("找到了,并且把该节点的值乘10\n"); 
	}
	else
	{
		printf("没找到\n");
	}
	Listprint(plist);
	
	ListInsert(pos,300);//指定位置插入测试 
	Listprint(plist);
	
	ListErase(pos);//指定位置删除测试 
	Listprint(plist);
	
	ListDestory(plist);
}

int main()
{
	//TestList1();
	TestList2();
} 
