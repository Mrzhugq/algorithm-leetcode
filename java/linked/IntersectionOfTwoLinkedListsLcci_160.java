package linked;

/**
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 */
public class IntersectionOfTwoLinkedListsLcci_160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode curA = headA;
        ListNode curB = headB;
        int lenA = 0, lenB = 0;
        // 求长度
        while (curA != null) {
            curA = curA.next;
            lenA++;
        }
        while (curB != null) {
            curB = curB.next;
            lenB++;
        }
        // 让curA为最长链表的头
        curA = headA;
        curB = headB;
        if (lenA < lenB) {
            int temp1 = lenA;
            lenA = lenB;
            lenB = temp1;
            ListNode temp2 = curA;
            curA = curB;
            curB = temp2;
        }
        // 长度差
        int gap = lenA - lenB;
        while (gap-- != 0) {
            curA = curA.next;
        }
        while (curA != null) {
            if (curA == curB) {
                return curA;
            }
            curA = curA.next;
            curB = curB.next;
        }
        return null;
    }
}
