/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    int carry=0;

    while(l1!=NULL || l2!=NULL)
    {
        int val1 = l1!=NULL ? l1->val : 0;
        int val2 = l2!=NULL ? l2->val : 0;
        int sum=val1+val2+carry;
        if(head==NULL)
        {
            head=tail=(struct ListNode*)malloc(sizeof(struct ListNode));
            tail->val=sum%10;
            tail->next=NULL;
        }
        else
        {
            tail->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            tail->next->val=sum%10;

            tail=tail->next;
            tail->next = NULL;   
        }
        carry=sum/10;
		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
    }
    if (carry > 0)
	{
		tail->next =(struct ListNode*)malloc(sizeof(struct ListNode));
		tail->next->val = carry;
		tail->next->next = NULL;
	}
    return head;
}
