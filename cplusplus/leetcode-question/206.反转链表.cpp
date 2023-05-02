/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//1. 
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head;

    while(next != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}



//2. 
//          a   ->   b    ->   c   ->   NULL
//递归一次          head    Newhead       
struct ListNode* reverseList(struct ListNode* head)
{
	if(head==NULL || head->next==NULL) //第一次找到 c
	{
		return head;
	}
	struct ListNode* Newhead=reverseList(head->next);
	head->next->next=head;             // c->next=b
	head->next=NULL;                   //b->next=NULL
	
	return Newhead;
}
