package binarytree;

/**
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 */
public class SumOfLeftLeaves_404 {

    public int sumOfLeftLeaves(TreeNode root) {
        return getLeftLeavesSum(root);
    }

    private int getLeftLeavesSum(TreeNode root) {
        if (root == null) return 0;
        int leftValue = getLeftLeavesSum(root.left);
        int rightValue = getLeftLeavesSum(root.right);

        int sum = leftValue + rightValue;
        // 通过父亲节点和本身的孩子判断是不是左叶子
        if (root.left != null && root.left.left == null && root.left.right == null) {
            sum += root.left.val;
        }
        return sum;
    }

}
