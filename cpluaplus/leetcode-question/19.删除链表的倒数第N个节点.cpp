/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//1.----------------------------------------------------------------------------------
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    dummy->val = 0;
    dummy->next = head;

    int len = 0;
    struct ListNode* temp = head;
    while(temp != NULL)//先求出链表的长度
    {
        temp = temp->next;
        len++;
    }

    struct ListNode* cur = dummy;
    for(int i=1; i<(len-n+1); i++)
    {
        //找到要删除节点的前一个,要删除的是第(len-n+1)个,注意循环条件 -> 循环执行(len-n+1)-1次
        cur = cur->next;
    }
    cur->next = cur->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}


// //这样的无头的不能解决删除第一个的情况
// struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
// {
//     int len = 0;
//     struct ListNode* temp = head;
//     while(temp != NULL)//先求出链表的长度
//     {
//         temp = temp->next;
//         len++;
//     }

//     struct ListNode* cur = head;
//     for(int i=0; i<(len-n+1)-2; i++)
//     {
//         //找到要删除节点的前一个,要删除的是第(len-n+1)个 -> 循环执行(len-n+1)-2次
//         cur = cur->next;
//     }
//     cur->next = cur->next->next;
//     return head;
// }









//2.----------------------------------------------------------------------------------------------
//快慢指针  ->   妙
//由于我们需要找到倒数第 n 个节点，因此我们可以使用两个指针 fast 和 slow 同时对链表进行遍历
//并且 fast 比 slow 超前 n 个节点。当 fast 遍历到链表的末尾时，slow就恰好处于要删除节点的前一个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = malloc(sizeof(struct ListNode) * 1);
	dummy->val = 0;
	dummy->next = head;

    struct ListNode* fast = head;
    struct ListNode* slow = dummy;
    for(int i=0; i<n; i++)//fast 比 slow 超前 n 个节点
    {
        fast = fast->next;
    }

    while(fast != NULL)//当fast 遍历到链表的末尾时,slow就恰好处于要删除节点的前一个节点
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}
