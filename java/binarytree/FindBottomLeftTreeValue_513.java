package binarytree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 */
public class FindBottomLeftTreeValue_513 {

    private int maxDepth = Integer.MIN_VALUE;
    private int res = 0;

    public int findBottomLeftValue(TreeNode root) {
        traversal(root, 0);
        return res;
    }

    // DFS 在树的最后一行找到最左边的值 (深度最大的叶子节点一定是最后一行)
    private void traversal(TreeNode cur, int depth) {
        if (cur.left == null && cur.right == null) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = cur.val;
            }
            return;
        }

        if (cur.left != null) {
            depth++;
            traversal(cur.left, depth);
            depth--; // 回溯
        }
        if (cur.right != null) {
            depth++;
            traversal(cur.right, depth);
            depth--;
        }
    }

    // BFS
    public int findBottomLeftValue2(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        if (root != null) {
            queue.offer(root);
        }
        int res = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (i == 0) res = node.val;
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        return res;
    }

}
