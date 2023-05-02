/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//1.--------------------------------------------------------------------------------- 
//�����н���
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* curA = headA; 
        ListNode* curB = headB;
        while(curA != curB)
        {
            curA = (curA != NULL ? curA->next : headB);
            curB = (curB != NULL ? curB->next : headA);
        } 
        return curA;
    }
};



/*
 A
       D    C
 B
��Ϊ�������A������B�ཻ��D�Ļ�,��ô˵��D��㼴��A������B��,��D֮���Ԫ����ȻҲ�;���A��B����,��Ϊ������ͨ��nextָ��������.
������ཻ�Ľ��D�Ļ�,ÿ������ͷ����������Լ���������,Ȼ���ͷ�������һ������,��ô�����һ��Ϊ�ཻ��D��,
��Ϊ��ʱÿ��ͷ����ߵľ�����һ����,���� AD + BD + DC,������ÿ���ֶ���ǰ��1,
���Ծ�����ͬ,�ٶ�����ͬ,��Ȼһ��������ͬ��ʱ���ߵ���ͬ�Ľ����,��D��


A   C   NULL  
B   D   E     NULL
������ཻ ��
1. ������ཻ�Ļ� �������������Ȳ���� һ��ΪlenA һ��ΪlenB ��ָ���һ������A��ȥ��B,
��һ������B��ȥ��A������ָ���ߵ�·�̶���lenA+lenB����ͬʱΪNULL ����ѭ��
2.������ཻ�����������: ��ôһ��ָ����A,һ��ָ����B������ͬʱ�ߵ�NULL����ȣ�����ѭ��

������ཻ�Ļ�����������������ĳ��Ⱥ�����curA==curB==NULL;
��Ϊ����·��һ����󶼻��ߵ�NULL
 */
 
 
 
 //2.-----------------------------------------------------------------------------------
 class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0,lenB = 0;
        while(curA != NULL) //�ȱ���һ�����������
        {
            lenA++;
            curA = curA->next;
        }
        while(curB != NULL)
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        //��curAΪ������ͷ��lenҲҪ��
        if(lenB > lenA)
        {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;//���Ȳ�
        //��curA��curA��ͬһ����ϣ�ĩβλ�ö��룩
        while(gap--)
        {
            curA = curA->next;
        }
        while(curA != NULL)
        {
            if(curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
}; 
