package binarytree;

import java.util.*;

/**
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 */
public class CountCompleteTreeNodes_222 {

    // DFS
    public int countNodes(TreeNode root) {
        return getNodeNum(root);
    }

    // 后续遍历
    private int getNodeNum(TreeNode cur) {
        if (cur == null) return 0;
        int leftNum = getNodeNum(cur.left);
        int rightNum = getNodeNum(cur.right);
        return leftNum + rightNum + 1;
    }

    // BFS
    public int countNodes2(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        if (root != null) {
            queue.offer(root);
        }
        int res = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                res++;
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
