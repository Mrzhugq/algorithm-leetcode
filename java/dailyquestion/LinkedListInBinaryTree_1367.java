package dailyquestion;

import binarytree.TreeNode;
import linked.ListNode;

/**
 * <a href="https://leetcode.cn/problems/linked-list-in-binary-tree/description/">二叉树中的链表</a>
 *
 * @author sutong
 * @date 2024-12-31 14:07
 */
public class LinkedListInBinaryTree_1367 {

    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    public boolean dfs(ListNode head, TreeNode rt) {
        // 链表已经全部匹配完，匹配成功
        if (head == null) {
            return true;
        }
        // 二叉树访问到了空节点，匹配失败
        if (rt == null) {
            return false;
        }
        if (head.val != rt.val) {
            return false;
        }
        return dfs(head.next, rt.left) || dfs(head.next, rt.right);
    }
}
