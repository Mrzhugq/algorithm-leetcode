/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//1.--------------------------------------------------------------------------------- 
//下面有解释
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
因为如果链表A和链表B相交于D的话,那么说明D结点即在A上又在B上,而D之后的元素自然也就均在A和B上了,因为他们是通过next指针相连的.
如果有相交的结点D的话,每条链的头结点先走完自己的链表长度,然后回头走另外的一条链表,那么两结点一定为相交于D点,
因为这时每个头结点走的距离是一样的,都是 AD + BD + DC,而他们每次又都是前进1,
所以距离相同,速度又相同,固然一定会在相同的时间走到相同的结点上,即D点


A   C   NULL  
B   D   E     NULL
如果不相交 ：
1. 如果不相交的话 假设两个链表长度不相等 一个为lenA 一个为lenB ，指针第一次走完A会去走B,
另一个走完B再去走A，两个指针走的路程都是lenA+lenB。会同时为NULL 跳出循环
2.如果不相交且链表长度相等: 那么一个指针走A,一个指针走B，它俩同时走到NULL，相等，跳出循环

如果不相交的话，当走了两个链表的长度后，最终curA==curB==NULL;
因为它们路程一样最后都会走到NULL
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
        while(curA != NULL) //先遍历一遍算出来长度
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
        //让curA为最长链表的头，len也要换
        if(lenB > lenA)
        {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;//长度差
        //让curA和curA在同一起点上（末尾位置对齐）
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
