#include "SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	// 想在3的前面插入一个30
	SLTNode* pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);

	pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 1);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);

	pos = SListFind(plist, 4);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);

	pos = SListFind(plist, 3);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);

	pos = SListFind(plist, 2);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
}


int main()
{
	TestSList4();

	return 0;
}