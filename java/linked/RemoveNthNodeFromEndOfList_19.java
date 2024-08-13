package linked;

/**
 * <a href="https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/">删除链表的倒数第 N 个结点</a>
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
public class RemoveNthNodeFromEndOfList_19 {
    // 一次遍历 双指针
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode slow = dummyHead;
        ListNode fast = dummyHead;
        while (n-- != 0 && fast != null) {
            fast = fast.next;
        }
        fast = fast.next; // 走n + 1步（这样才能让slow指向删除节点的上一个节点）
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummyHead.next;
    }

    // 两次遍历 计算长度
    public ListNode removeNthFromEnd2(ListNode head, int n) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode cur = dummyHead.next;
        int size = 0;
        while (cur != null) {
            cur = cur.next;
            size++;
        }

        int loop = size - n;
        cur = dummyHead;
        while (loop-- > 0) {
            cur = cur.next;
        }
        cur.next = cur.next.next;
        return dummyHead.next;
    }
}
