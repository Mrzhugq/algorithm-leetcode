/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//穿针引线
//加个虚拟头节点方便
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode* dummyNode =  new ListNode(0);
        dummyNode->next = head;

        ListNode* prev = dummyNode; //prev永远指向待反转链表区间的第一个节点left的前一个节点，循环中prev不变
        for(int i=0; i<left-1; i++)
        {
            prev = prev->next;
        }
        ListNode* cur = prev->next; //指向待反转区域的第一个节点 left
        ListNode* next;             //永远指向 cur 的下一个节点，循环过程中，cur 变化以后 next 会变化
        for(int i=0; i<right-left; i++)
        {
            next = cur->next;

            //注意下面三局语句顺序
            cur->next = next->next;
            next->next = prev->next; 
            //不能这样写next->next = cur; 
            //第一次循环对，第二次循环就不对了，因为cur是变换的，而prev->next永远指向待反转链表区间的第一个节点
            prev->next = next;
        }
        ListNode* res = dummyNode->next;
        delete dummyNode;
        return res;
    }
};


