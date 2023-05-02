/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//1. 带头 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;

    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    //取小的尾插
    head=tail=(struct ListNode*)malloc(sizeof(struct ListNode));//带头链表

    while(l1!=NULL && l2!=NULL)//其中一个为空结束
    {
        if(l1->val < l2->val)
        {
            tail->next=l1;
            tail=tail->next;
            
            l1=l1->next;
        }
        else
        {

            tail->next=l2;
            tail=tail->next;

            l2=l2->next;
        }
    }
    //把剩下的不为空的直接插到后面
    if(l1!=NULL)
    {
        tail->next=l1;
    }
    if(l2!=NULL)
    {
        tail->next=l2;
    }
    
    struct ListNode* ret=head->next;
    free(head);
    return ret;
}


//2.不带头 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;

    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    //取小的尾插

    if(l1->val <l2->val)//找一个小的做头
    {
        tail=head=l1;
        l1=l1->next;
    }
    else
    {
        tail=head=l2;
        l2=l2->next;
    }

    while(l1!=NULL && l2!=NULL)//其中一个为空结束
    {
        if(l1->val < l2->val)
        {
            tail->next=l1;
            tail=tail->next;
            
            l1=l1->next;
        }
        else
        {

            tail->next=l2;
            tail=tail->next;

            l2=l2->next;
        }
    }
    //把剩下的不为空的直接插到后面
    if(l1!=NULL)
    {
        tail->next=l1;
    }
    if(l2!=NULL)
    {
        tail->next=l2;
    }

    return head;
} 


