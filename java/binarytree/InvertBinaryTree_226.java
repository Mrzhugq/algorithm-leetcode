package binarytree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 */
public class InvertBinaryTree_226 {
    // DFS
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        swapChildren(root);          // 中
        invertTree(root.left);       // 左
        invertTree(root.right);      // 右
        return root;
    }

    // BFS
    public TreeNode invertTree2(TreeNode root) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        if (root != null) {
            queue.offer(root);
        }
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                swapChildren(node);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        return root;
    }

    private void swapChildren(TreeNode node) {
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
