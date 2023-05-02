/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//1. ��ͷ 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;

    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    //ȡС��β��
    head=tail=(struct ListNode*)malloc(sizeof(struct ListNode));//��ͷ����

    while(l1!=NULL && l2!=NULL)//����һ��Ϊ�ս���
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
    //��ʣ�µĲ�Ϊ�յ�ֱ�Ӳ嵽����
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


//2.����ͷ 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;

    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    //ȡС��β��

    if(l1->val <l2->val)//��һ��С����ͷ
    {
        tail=head=l1;
        l1=l1->next;
    }
    else
    {
        tail=head=l2;
        l2=l2->next;
    }

    while(l1!=NULL && l2!=NULL)//����һ��Ϊ�ս���
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
    //��ʣ�µĲ�Ϊ�յ�ֱ�Ӳ嵽����
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


