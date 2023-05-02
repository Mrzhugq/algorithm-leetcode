#include<stdio.h>
#include<stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
 
 
//1.˫ָ������м�ڵ�+��ָ�뷴ת����Ƚ�+��ԭ���� 
struct ListNode* MidNode(struct ListNode* head)//���м�ڵ�
{
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    } 
    return slow;
}


struct ListNode* ReverseNode(struct ListNode *second)//��ָ�뷴ת����
{
    struct ListNode *first=NULL;
    while(second != NULL)
    {
        struct ListNode *thirdly=second->next;
        second->next=first;
        first=second;
        second=thirdly;
    }
    return first;
}

bool isPalindrome(struct ListNode* head)
{
    if (head == NULL) 
    {
        return true;
    }
    struct ListNode *mid=MidNode(head);
    struct ListNode *rev=ReverseNode(mid);
    
    struct ListNode *pp=rev;//��¼�������ԭ����ԭ����
    while(rev != NULL) 
    {
        if(head->val != rev->val)
        {
            return false;
        }
        head=head->next;
        rev=rev->next;
    }

    mid->next=ReverseNode(pp);//��ԭ����
    return true;
}



////2.ת��Ϊ����
//bool isPalindrome(struct ListNode* head)
//{
//    int data[100000],count=0;
//    while(head!=NULL)
//    {
//        data[count++]=head->val;
//        head=head->next;
//    }
//    for(int i=0,j=count-1; i<j; i++,j--)
//    {
//        if(data[i]!=data[j])
//        return false;
//    }
//    return true;
//} 




int main()
{
	struct ListNode* a=(struct ListNode*)malloc(sizeof(struct ListNode));
	a->val=1;
	
	struct ListNode* b=(struct ListNode*)malloc(sizeof(struct ListNode));
	b->val=2;
	
	struct ListNode* c=(struct ListNode*)malloc(sizeof(struct ListNode));
	c->val=2;
	
	struct ListNode* d=(struct ListNode*)malloc(sizeof(struct ListNode));
	d->val=1;
	
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=NULL;
	printf("%d ",isPalindrome(a));
} 
