package linked;

/**
 * <a href="https://leetcode.cn/problems/design-linked-list/description/">设计链表</a>
 * 你可以选择使用单链表或者双链表，设计并实现自己的链表。
 * 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
 * 如果是双向链表，则还需要属性prev以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
 * <p>
 * 实现 MyLinkedList 类：
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
 * void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
 * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
 * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
 * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 */
public class DesignLinkedList_707 {
    public static void main(String[] args) {
        MyLinkedList linkedList = new MyLinkedList();
        linkedList.addAtHead(1);
        linkedList.addAtTail(3);
        linkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
        linkedList.get(1);                        // 返回 2
        linkedList.deleteAtIndex(1);              // 现在，链表变为 1->3
        linkedList.get(1);                        // 返回 3
    }

    static class MyLinkedList {
        private int size;
        private ListNode dummyHead; // 虚拟节点

        //  dummy -> 1 -> 2- > 3
        public MyLinkedList() {
            size = 0;
            dummyHead = new ListNode(0);
        }

        public int get(int index) {
            if (index < 0 || index > size - 1) {
                return -1;
            }
            ListNode cur = dummyHead.next; // 注意
            while (index-- != 0) {
                cur = cur.next;
            }
            return cur.val;
        }

        public void addAtHead(int val) {
            ListNode node = new ListNode(val);
            node.next = dummyHead.next;
            dummyHead.next = node;
            size++;
        }

        public void addAtTail(int val) {
            ListNode node = new ListNode(val);
            ListNode cur = dummyHead;
            while (cur.next != null) {
                cur = cur.next;
            }
            cur.next = node;
            size++;
        }

        public void addAtIndex(int index, int val) {
            if (index > size) return;
            if (index < 0) index = 0;
            ListNode node = new ListNode(val);
            ListNode cur = dummyHead;
            while (index-- != 0) {
                cur = cur.next;
            }
            node.next = cur.next;
            cur.next = node;
            size++;
        }

        public void deleteAtIndex(int index) {
            if (index < 0 || index > size - 1) {
                return;
            }
            ListNode cur = dummyHead;
            while (index-- != 0) {
                cur = cur.next;
            }
            cur.next = cur.next.next;
            size--;
        }

        public void printLinkedList() {
            ListNode cur = dummyHead;
            while (cur.next != null) {
                System.out.print(cur.next.val + " ");
                cur = cur.next;
            }
            System.out.println();
        }
    }
}