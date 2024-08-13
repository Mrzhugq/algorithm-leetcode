package linked;

/**
 * <a href="https://leetcode.cn/problems/linked-list-cycle-ii/description/">环形链表 II</a>
 * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 */
public class LinkedListCycleII_142 {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {  // 有环
                ListNode index1 = head;
                ListNode index2 = fast;
                while (index1 != index2) {
                    index1 = index2.next;
                    index2 = index2.next;
                }
                return index1; // 环的入口（一个指针从相遇处开始走，一个指针从head走，他们会在环的入口处相遇）
            }
        }
        return null;
    }
}
