//迭代反转链表 
//                  a   ->   b   ->   c   ->   NULL
//         NULL
//第一次   pre     cur      temp
//第二次           pre       cur      temp
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

//递归反转链表 

//          a   ->   b    ->   c   ->   NULL
//递归一次          head    Newhead       
struct ListNode* reverseList(struct ListNode* head)
{
	if(head==NULL || head->next==NULL) //第一次找到 c
	{
		return head;
	}
	struct ListNode* Newhead=reverseList(head->next);
	head->next->next=head;             // c->next=b
	head->next=NULL;                   //b->next=NULL
	
	return Newhead;
} 






 
