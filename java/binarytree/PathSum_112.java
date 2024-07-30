package binarytree;

/**
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 * 如果存在，返回 true ；否则，返回 false 。
 */
public class PathSum_112 {

    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;
        return traversal(root, targetSum - root.val);
    }

    private boolean traversal(TreeNode cur, int count) {
        if (cur.left == null && cur.right == null) {
            // count减到0且到叶子节点了算找到了
            return count == 0;
        }
        if (cur.left != null) {
            count -= cur.left.val;
            if (traversal(cur.left, count)) return true;
            count += cur.left.val; // 回溯
        }
        if (cur.right != null) {
            count -= cur.right.val;
            if (traversal(cur.right, count)) return true;
            count += cur.right.val;
        }
        return false;
    }

}
