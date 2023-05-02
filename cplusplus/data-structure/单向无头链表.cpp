#include<stdio.h>
#include<stdlib.h>


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode; 


void SListPrint(SLTNode* phead)//打印链表 
{
	SLTNode* cur = phead;
	while(cur != NULL)
	{
        printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("NULL"); 
}


SLTNode* BuySListNode(SLTDataType x)//开辟一个新的节点 
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode) * 1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


void SListPushBack(SLTNode** pphead, SLTDataType x)//尾插 -> 需要讨论没有节点的情况 
{
	SLTNode* newnode = BuySListNode(x);//创建一个新节点 
	
	if(*pphead == NULL)//这里是当链表一个节点也没有的情况，需要分开讨论 
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;//想要尾插必须找到最后一个节点 
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		//链接尾节点 
		tail->next = newnode; 
	}
}


void SListPushFront(SLTNode** pphead, SLTDataType x)//头插
{
    SLTNode* newnode = BuySListNode(x);//创建一个新节点 
    
	newnode->next = *pphead; //如果链表一个节点也没有也行，不需要分开讨论 
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)//尾删  ->  需要讨论只有一个节点或没有节点 
{
	if(*pphead == NULL)//空链表直接结束 
	{
		return;
    }
    else if((*pphead)->next == NULL)//只有一个节点的时候 
    {
    	free(*pphead);
    	*pphead = NULL;
	}
	else//有一个以上的节点 
	{
        SLTNode* prev = NULL; 
		SLTNode* tail = *pphead;
		while(tail->next != NULL)//要找到尾节点和尾节点的前一个节点 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL; 
    } 
}

void SListPopFront(SLTNode** pphead)//头删 
{
	if(*pphead == NULL)//空链表直接结束 
	{
		return;
    }
    else
    {
   	    SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next; 
	}
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)//查找某个节点(不改变plist,可以传一级指针) 
{
	SLTNode* cur = phead;
	while(cur != NULL)
	{
		if(cur->data == x)
		{
			return cur;
	    } 
	    cur = cur->next;
	}
	return NULL;
}

//要考虑头插特殊情况，尾插不用考虑 
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//在pos节点前面插入一个节点 
{
	if(pos == *pphead)//如果是在第一个节点前面插入，直接调用前面的头插函数 
	{
		SListPushFront(pphead, x); 
    } 
    else
    {
        SLTNode* newnode = BuySListNode(x);//创建一个新节点 
        
	    SLTNode* prev = *pphead;//需要找到pos的前一个节点 
	    while(prev->next != pos)
	    {
	    	prev = prev->next;
		}
		//链接新节点 
		prev->next = newnode;
		newnode->next = pos; 
	}

}

//要考虑头删特殊情况，尾删不用考虑
void SListErase(SLTNode** pphead, SLTNode* pos)//删除pos位置的值  -> 删除pos节点 
{
    if(pos == *pphead)//如果是删除第一个节点，prev找不到前一个节点，需要讨论 
	{
		SListPopFront(pphead); 
    } 
    else
    {
        SLTNode* prev = *pphead;//需要找到pos的前一个节点 
	    while(prev->next != pos)
	    {
	    	prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
} 









void test1()
{
    SLTNode* plist = NULL;
	SListPushBack(&plist,1);//尾插 
	SListPushBack(&plist,2); 
	
	SListPushFront(&plist,3);//头插 
	SListPushFront(&plist,4);
	
	SListPopBack(&plist);//尾删 
	SListPopBack(&plist);
	
	SListPopFront(&plist);//头删 
	SListPopFront(&plist);

	SListPrint(plist); 
} 


void test2()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist,1);//尾插几个数据 
    SListPushBack(&plist,2); 
    SListPushBack(&plist,3); 
    SListPushBack(&plist,4); 
    
    //在3节点前面插入30
    SLTNode* pos = SListFind(plist, 3);
	if(pos)
	{
		SListInsert(&plist, pos, 30);
    } 
    
    //删除2节点 
    SLTNode* pos2 = SListFind(plist, 2);
	if(pos2)
	{
		SListErase(&plist, pos2);
    } 
    SListPrint(plist); 
}


int main()
{
	//test1();
	test2();
	return 0; 
}

