package binarytree;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;

/**
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 */
public class SymmetricTree_101 {

    // 递归法
    // 判断根节点的左子树反转后是否和右子树相等
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return compare(root.left, root.right);
    }

    private boolean compare(TreeNode left, TreeNode right) {
        if (left == null && right != null) return false;
        else if (left != null && right == null) return false;
        else if (left == null && right == null) return true;
        else if (left.val != right.val) return false;

        boolean res1 = compare(left.left, right.right);  // 左子树：左、 右子树：右
        boolean res2 = compare(left.right, right.left);  // 左子树：右、 右子树：左
        return res1 && res2;
    }


    // 迭代法 （不是层序遍历）
    public boolean isSymmetric2(TreeNode root) {
        if (root == null) return true;
        Deque<TreeNode> queue = new LinkedList<>(); // ArrayDeque不允许插入null
        queue.offer(root.left);
        queue.offer(root.right);
        while (!queue.isEmpty()) {
            TreeNode node1 = queue.poll();
            TreeNode node2 = queue.poll();
            if (node1 == null && node2 == null) {
                continue;
            }
            if (node1 == null && node2 != null) {
                return false;
            }
            if (node1 != null && node2 == null) {
                return false;
            }
            if (node1.val != node2.val) {
                return false;
            }
            queue.offer(node1.left);
            queue.offer(node2.right);
            queue.offer(node1.right);
            queue.offer(node2.left);
        }
        return true;
    }
}
