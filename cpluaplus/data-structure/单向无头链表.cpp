#include<stdio.h>
#include<stdlib.h>


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode; 


void SListPrint(SLTNode* phead)//��ӡ���� 
{
	SLTNode* cur = phead;
	while(cur != NULL)
	{
        printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("NULL"); 
}


SLTNode* BuySListNode(SLTDataType x)//����һ���µĽڵ� 
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode) * 1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


void SListPushBack(SLTNode** pphead, SLTDataType x)//β�� -> ��Ҫ����û�нڵ����� 
{
	SLTNode* newnode = BuySListNode(x);//����һ���½ڵ� 
	
	if(*pphead == NULL)//�����ǵ�����һ���ڵ�Ҳû�е��������Ҫ�ֿ����� 
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;//��Ҫβ������ҵ����һ���ڵ� 
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		//����β�ڵ� 
		tail->next = newnode; 
	}
}


void SListPushFront(SLTNode** pphead, SLTDataType x)//ͷ��
{
    SLTNode* newnode = BuySListNode(x);//����һ���½ڵ� 
    
	newnode->next = *pphead; //�������һ���ڵ�Ҳû��Ҳ�У�����Ҫ�ֿ����� 
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)//βɾ  ->  ��Ҫ����ֻ��һ���ڵ��û�нڵ� 
{
	if(*pphead == NULL)//������ֱ�ӽ��� 
	{
		return;
    }
    else if((*pphead)->next == NULL)//ֻ��һ���ڵ��ʱ�� 
    {
    	free(*pphead);
    	*pphead = NULL;
	}
	else//��һ�����ϵĽڵ� 
	{
        SLTNode* prev = NULL; 
		SLTNode* tail = *pphead;
		while(tail->next != NULL)//Ҫ�ҵ�β�ڵ��β�ڵ��ǰһ���ڵ� 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL; 
    } 
}

void SListPopFront(SLTNode** pphead)//ͷɾ 
{
	if(*pphead == NULL)//������ֱ�ӽ��� 
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

SLTNode* SListFind(SLTNode* phead, SLTDataType x)//����ĳ���ڵ�(���ı�plist,���Դ�һ��ָ��) 
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

//Ҫ����ͷ�����������β�岻�ÿ��� 
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//��pos�ڵ�ǰ�����һ���ڵ� 
{
	if(pos == *pphead)//������ڵ�һ���ڵ�ǰ����룬ֱ�ӵ���ǰ���ͷ�庯�� 
	{
		SListPushFront(pphead, x); 
    } 
    else
    {
        SLTNode* newnode = BuySListNode(x);//����һ���½ڵ� 
        
	    SLTNode* prev = *pphead;//��Ҫ�ҵ�pos��ǰһ���ڵ� 
	    while(prev->next != pos)
	    {
	    	prev = prev->next;
		}
		//�����½ڵ� 
		prev->next = newnode;
		newnode->next = pos; 
	}

}

//Ҫ����ͷɾ���������βɾ���ÿ���
void SListErase(SLTNode** pphead, SLTNode* pos)//ɾ��posλ�õ�ֵ  -> ɾ��pos�ڵ� 
{
    if(pos == *pphead)//�����ɾ����һ���ڵ㣬prev�Ҳ���ǰһ���ڵ㣬��Ҫ���� 
	{
		SListPopFront(pphead); 
    } 
    else
    {
        SLTNode* prev = *pphead;//��Ҫ�ҵ�pos��ǰһ���ڵ� 
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
	SListPushBack(&plist,1);//β�� 
	SListPushBack(&plist,2); 
	
	SListPushFront(&plist,3);//ͷ�� 
	SListPushFront(&plist,4);
	
	SListPopBack(&plist);//βɾ 
	SListPopBack(&plist);
	
	SListPopFront(&plist);//ͷɾ 
	SListPopFront(&plist);

	SListPrint(plist); 
} 


void test2()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist,1);//β�弸������ 
    SListPushBack(&plist,2); 
    SListPushBack(&plist,3); 
    SListPushBack(&plist,4); 
    
    //��3�ڵ�ǰ�����30
    SLTNode* pos = SListFind(plist, 3);
	if(pos)
	{
		SListInsert(&plist, pos, 30);
    } 
    
    //ɾ��2�ڵ� 
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

