package binarytree;

import java.util.ArrayList;
import java.util.List;

/**
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 */
public class BinaryTreePreorderTraversal_144 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        traversal(res, root);
        return res;
    }

    private void traversal(List<Integer> res, TreeNode cur) {
        if (cur == null) return;
        res.add(cur.val);          // 中
        traversal(res, cur.left);  // 左
        traversal(res, cur.right); // 右
    }
}