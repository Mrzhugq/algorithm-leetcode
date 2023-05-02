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
            //���ۣ�һ��ָ�����������ʼ�ߣ�һ��ָ���head�ߣ����ǻ��ڻ�����ڴ�����
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
