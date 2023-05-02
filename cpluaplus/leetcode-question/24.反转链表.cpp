//1.反转链表（迭代思想） 
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL)
    return NULL;
    struct ListNode *n1=NULL,*n2=head,*n3=n2->next;
    while(n2!=NULL)
    {
        n2->next=n1;

        n1=n2;
        n2=n3;
        if(n3!=NULL)
        n3=n3->next;
    }
    return n1;
}

//1.反转链表（头插法）
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur=head;
    struct ListNode* newnode=NULL;
    while(cur!=NULL)
    {
        struct ListNode* next=cur->next;

        cur->next=newnode;
        newnode=cur;
        cur=next;
    }
    return newnode;
} 
