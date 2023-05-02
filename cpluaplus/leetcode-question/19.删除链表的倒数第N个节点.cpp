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
    while(temp != NULL)//���������ĳ���
    {
        temp = temp->next;
        len++;
    }

    struct ListNode* cur = dummy;
    for(int i=1; i<(len-n+1); i++)
    {
        //�ҵ�Ҫɾ���ڵ��ǰһ��,Ҫɾ�����ǵ�(len-n+1)��,ע��ѭ������ -> ѭ��ִ��(len-n+1)-1��
        cur = cur->next;
    }
    cur->next = cur->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}


// //��������ͷ�Ĳ��ܽ��ɾ����һ�������
// struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
// {
//     int len = 0;
//     struct ListNode* temp = head;
//     while(temp != NULL)//���������ĳ���
//     {
//         temp = temp->next;
//         len++;
//     }

//     struct ListNode* cur = head;
//     for(int i=0; i<(len-n+1)-2; i++)
//     {
//         //�ҵ�Ҫɾ���ڵ��ǰһ��,Ҫɾ�����ǵ�(len-n+1)�� -> ѭ��ִ��(len-n+1)-2��
//         cur = cur->next;
//     }
//     cur->next = cur->next->next;
//     return head;
// }









//2.----------------------------------------------------------------------------------------------
//����ָ��  ->   ��
//����������Ҫ�ҵ������� n ���ڵ㣬������ǿ���ʹ������ָ�� fast �� slow ͬʱ��������б���
//���� fast �� slow ��ǰ n ���ڵ㡣�� fast �����������ĩβʱ��slow��ǡ�ô���Ҫɾ���ڵ��ǰһ���ڵ�
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = malloc(sizeof(struct ListNode) * 1);
	dummy->val = 0;
	dummy->next = head;

    struct ListNode* fast = head;
    struct ListNode* slow = dummy;
    for(int i=0; i<n; i++)//fast �� slow ��ǰ n ���ڵ�
    {
        fast = fast->next;
    }

    while(fast != NULL)//��fast �����������ĩβʱ,slow��ǡ�ô���Ҫɾ���ڵ��ǰһ���ڵ�
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}
