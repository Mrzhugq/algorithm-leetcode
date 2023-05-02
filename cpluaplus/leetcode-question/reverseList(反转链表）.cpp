//������ת���� 
//                  a   ->   b   ->   c   ->   NULL
//         NULL
//��һ��   pre     cur      temp
//�ڶ���           pre       cur      temp
// ..... 
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* pre=NULL;
	struct ListNode* cur=head;
	
	while(cur)
	{
		struct ListNode* temp=cur->next;
		cur->next=pre;
		
		pre=cur;
		cur=temp;
	}
	return pre;
}

//�ݹ鷴ת���� 

//          a   ->   b    ->   c   ->   NULL
//�ݹ�һ��          head    Newhead       
struct ListNode* reverseList(struct ListNode* head)
{
	if(head==NULL || head->next==NULL) //��һ���ҵ� c
	{
		return head;
	}
	struct ListNode* Newhead=reverseList(head->next);
	head->next->next=head;             // c->next=b
	head->next=NULL;                   //b->next=NULL
	
	return Newhead;
} 






 
