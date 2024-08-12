package linked;

/**
 * <a href="https://leetcode.cn/problems/reverse-linked-list/description/">反转链表</a>
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */
public class ReverseLinkedList_206 {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
}
