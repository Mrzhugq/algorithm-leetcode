/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//��������
//�Ӹ�����ͷ�ڵ㷽��
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        // ���� dummyNode ����һ�������һ������
        ListNode* dummyNode =  new ListNode(0);
        dummyNode->next = head;

        ListNode* prev = dummyNode; //prev��Զָ�����ת��������ĵ�һ���ڵ�left��ǰһ���ڵ㣬ѭ����prev����
        for(int i=0; i<left-1; i++)
        {
            prev = prev->next;
        }
        ListNode* cur = prev->next; //ָ�����ת����ĵ�һ���ڵ� left
        ListNode* next;             //��Զָ�� cur ����һ���ڵ㣬ѭ�������У�cur �仯�Ժ� next ��仯
        for(int i=0; i<right-left; i++)
        {
            next = cur->next;

            //ע�������������˳��
            cur->next = next->next;
            next->next = prev->next; 
            //��������дnext->next = cur; 
            //��һ��ѭ���ԣ��ڶ���ѭ���Ͳ����ˣ���Ϊcur�Ǳ任�ģ���prev->next��Զָ�����ת��������ĵ�һ���ڵ�
            prev->next = next;
        }
        ListNode* res = dummyNode->next;
        delete dummyNode;
        return res;
    }
};


