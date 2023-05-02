struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            struct ListNode *meet=slow;
            //结论：一个指针从相遇处开始走，一个指针从head走，他们会在环的入口处相遇
            while(meet!=head)
            {
                head=head->next;
                meet=meet->next;
            }
            return meet;
        }
    }
    return NULL;
}
