#include "SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 找尾节点的指针
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		// 尾节点，链接新节点
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);

	*pphead = next;
}

void SListPopBack(SLTNode** pphead)
{
	// 1、空
	// 2、一个节点
	// 3、一个以上的节点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		prev->next = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SListNode* cur = phead;
	//while (cur != NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// 在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = newnode;
		newnode->next = pos;
	}
}

// 删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
	}
}