package binarytree;

import java.util.ArrayList;
import java.util.List;

/**
 * 给你一棵二叉树的根节点 root ，返回其节点值的 中序遍历 。
 */
public class BinaryTreeInorderTraversal_94 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        traversal(res, root);
        return res;
    }

    private void traversal(List<Integer> res, TreeNode cur) {
        if (cur == null) return;
        traversal(res, cur.left);
        res.add(cur.val);
        traversal(res, cur.right);
    }
}