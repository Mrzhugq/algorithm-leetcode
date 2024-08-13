package linked;

/**
 * <a href="https://leetcode.cn/problems/swap-nodes-in-pairs/description/">两两交换链表中的节点</a>
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 */
public class SwapNodesInPairs_24 {

    //  dummy ->  1 -> 2 -> 3 -> 4
    //   cur      t1   t2  t3
    public ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode cur = dummyHead;
        while (cur.next != null && cur.next.next != null) {
            ListNode temp1 = cur.next;
            ListNode temp2 = cur.next.next;
            ListNode temp3 = cur.next.next.next;
            cur.next = temp2; // 三步
            temp2.next = temp1;
            temp1.next = temp3;
            cur = cur.next.next; // cur移动两位，准备下一轮交换
        }
        return dummyHead.next;
    }
}
