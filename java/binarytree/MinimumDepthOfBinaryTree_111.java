package binarytree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 */
public class MinimumDepthOfBinaryTree_111 {

    // BFS
    public int minDepth(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        if (root != null) {
            queue.offer(root);
        }
        int minDepth = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            minDepth++;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
                if (node.left == null && node.right == null) {
                    return minDepth;
                }
            }
        }
        return minDepth;
    }


    // DFS
    public int minDepth2(TreeNode root) {
        return getDepth(root);
    }

    // 后序遍历 (和求最大深度还是有区别的)
    // 如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度
    // 如果右子树为空，左子树不为空，说明最小深度是 1 + 左子树的深度
    // 如果左右子树都不为空，返回左右子树深度的最小值 + 1
    private int getDepth(TreeNode node) {
        if (node == null) return 0;
        int leftDepth = getDepth(node.left);
        int rightDepth = getDepth(node.right);
        if (node.left == null && node.right != null) { // 因为是到叶子节点的最小深度
            return rightDepth + 1;
        }
        if (node.left != null && node.right == null) {
            return leftDepth + 1;
        }
        return Math.min(leftDepth, rightDepth) + 1;
    }
}
